/**
 *  @file
 *
 *  @brief Destroy a Condition Variable
 *  @ingroup POSIXAPI
 */

/*
 *  COPYRIGHT (c) 1989-2007.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/posix/condimpl.h>

/**
 *  11.4.2 Initializing and Destroying a Condition Variable,
 *         P1003.1c/Draft 10, p. 87
 */
int pthread_cond_destroy(
  pthread_cond_t           *cond
)
{
  POSIX_Condition_variables_Control *the_cond;
  ISR_lock_Context                   lock_context;

  _Objects_Allocator_lock();
  the_cond = _POSIX_Condition_variables_Get( cond, &lock_context );

  if ( the_cond == NULL ) {
    _Objects_Allocator_unlock();
    return EINVAL;
  }

  _POSIX_Condition_variables_Acquire_critical( the_cond, &lock_context );

  if ( !_Thread_queue_Is_empty( &the_cond->Wait_queue.Queue ) ) {
    _POSIX_Condition_variables_Release( the_cond, &lock_context );
    _Objects_Allocator_unlock();
    return EBUSY;
  }

  _Objects_Close(
    &_POSIX_Condition_variables_Information,
    &the_cond->Object
  );
  _POSIX_Condition_variables_Release( the_cond, &lock_context );
  _POSIX_Condition_variables_Destroy( the_cond );
  _POSIX_Condition_variables_Free( the_cond );
  _Objects_Allocator_unlock();
  return 0;
}
