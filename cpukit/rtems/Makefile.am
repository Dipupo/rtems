include $(top_srcdir)/automake/multilib.am
include $(top_srcdir)/automake/compile.am

noinst_LIBRARIES = librtems.a
librtems_a_CPPFLAGS = $(AM_CPPFLAGS)

# include

include_HEADERS = include/rtems.h

# include/rtems/rtems
include_rtems_rtemsdir = $(includedir)/rtems/rtems
include_rtems_rtems_HEADERS =

include_rtems_rtems_HEADERS += include/rtems/rtems/asr.h
include_rtems_rtems_HEADERS += include/rtems/rtems/asrimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/attr.h
include_rtems_rtems_HEADERS += include/rtems/rtems/attrimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/barrier.h
include_rtems_rtems_HEADERS += include/rtems/rtems/barrierimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/cache.h
include_rtems_rtems_HEADERS += include/rtems/rtems/clock.h
include_rtems_rtems_HEADERS += include/rtems/rtems/config.h
include_rtems_rtems_HEADERS += include/rtems/rtems/dpmem.h
include_rtems_rtems_HEADERS += include/rtems/rtems/dpmemimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/event.h
include_rtems_rtems_HEADERS += include/rtems/rtems/eventimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/intr.h
include_rtems_rtems_HEADERS += include/rtems/rtems/message.h
include_rtems_rtems_HEADERS += include/rtems/rtems/messageimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/modes.h
include_rtems_rtems_HEADERS += include/rtems/rtems/modesimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/object.h
include_rtems_rtems_HEADERS += include/rtems/rtems/options.h
include_rtems_rtems_HEADERS += include/rtems/rtems/optionsimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/part.h
include_rtems_rtems_HEADERS += include/rtems/rtems/partimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/ratemon.h
include_rtems_rtems_HEADERS += include/rtems/rtems/ratemonimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/region.h
include_rtems_rtems_HEADERS += include/rtems/rtems/regionimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/sem.h
include_rtems_rtems_HEADERS += include/rtems/rtems/semimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/signal.h
include_rtems_rtems_HEADERS += include/rtems/rtems/signalimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/smp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/status.h
include_rtems_rtems_HEADERS += include/rtems/rtems/statusimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/support.h
include_rtems_rtems_HEADERS += include/rtems/rtems/tasks.h
include_rtems_rtems_HEADERS += include/rtems/rtems/tasksimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/timer.h
include_rtems_rtems_HEADERS += include/rtems/rtems/timerimpl.h
include_rtems_rtems_HEADERS += include/rtems/rtems/types.h
include_rtems_rtems_HEADERS += mainpage.h

if HAS_MP
## We only build multiprocessing related files if HAS_MP was defined
include_rtems_rtems_HEADERS += include/rtems/rtems/eventmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/mp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/msgmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/partmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/regionmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/semmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/signalmp.h
include_rtems_rtems_HEADERS += include/rtems/rtems/taskmp.h
endif

## src
librtems_a_SOURCES = src/rtemsbuildid.c
librtems_a_SOURCES += src/rtemsbuildname.c
librtems_a_SOURCES += src/rtemsobjectgetname.c
librtems_a_SOURCES += src/rtemsobjectsetname.c
librtems_a_SOURCES += src/rtemsobjectidapimaximum.c
librtems_a_SOURCES += src/rtemsobjectidapiminimum.c
librtems_a_SOURCES += src/rtemsobjectidgetapi.c
librtems_a_SOURCES += src/rtemsobjectidgetclass.c
librtems_a_SOURCES += src/rtemsobjectidgetindex.c
librtems_a_SOURCES += src/rtemsobjectidgetnode.c
librtems_a_SOURCES += src/rtemsobjectapiminimumclass.c
librtems_a_SOURCES += src/rtemsobjectapimaximumclass.c
librtems_a_SOURCES += src/rtemsobjectgetapiname.c
librtems_a_SOURCES += src/rtemsobjectgetapiclassname.c
librtems_a_SOURCES += src/rtemsobjectgetclassinfo.c
librtems_a_SOURCES += src/rtemsobjectgetclassicname.c

## TASK_C_FILES
librtems_a_SOURCES += src/tasks.c
librtems_a_SOURCES += src/taskcreate.c
librtems_a_SOURCES += src/taskdelete.c
librtems_a_SOURCES += src/taskgetaffinity.c
librtems_a_SOURCES += src/taskgetscheduler.c
librtems_a_SOURCES += src/taskident.c
librtems_a_SOURCES += src/taskinitusers.c
librtems_a_SOURCES += src/taskissuspended.c
librtems_a_SOURCES += src/taskmode.c
librtems_a_SOURCES += src/taskrestart.c
librtems_a_SOURCES += src/taskresume.c
librtems_a_SOURCES += src/taskself.c
librtems_a_SOURCES += src/tasksetaffinity.c
librtems_a_SOURCES += src/tasksetpriority.c
librtems_a_SOURCES += src/tasksetscheduler.c
librtems_a_SOURCES += src/taskstart.c
librtems_a_SOURCES += src/tasksuspend.c
librtems_a_SOURCES += src/taskwakeafter.c
librtems_a_SOURCES += src/taskwakewhen.c
librtems_a_SOURCES += src/schedulergetprocessorset.c
librtems_a_SOURCES += src/schedulerident.c

## RATEMON_C_FILES
librtems_a_SOURCES += src/ratemon.c
librtems_a_SOURCES += src/ratemoncancel.c
librtems_a_SOURCES += src/ratemoncreate.c
librtems_a_SOURCES += src/ratemondelete.c
librtems_a_SOURCES += src/ratemongetstatus.c
librtems_a_SOURCES += src/ratemongetstatistics.c
librtems_a_SOURCES += src/ratemonresetstatistics.c
librtems_a_SOURCES += src/ratemonresetall.c
librtems_a_SOURCES += src/ratemonreportstatistics.c
librtems_a_SOURCES += src/ratemonident.c
librtems_a_SOURCES += src/ratemonperiod.c
librtems_a_SOURCES += src/ratemontimeout.c

## INTR_C_FILES
librtems_a_SOURCES += src/intrbody.c
librtems_a_SOURCES += src/intrcatch.c

## BARRIER_C_FILES
librtems_a_SOURCES += src/barrier.c
librtems_a_SOURCES += src/barriercreate.c
librtems_a_SOURCES += src/barrierdelete.c
librtems_a_SOURCES += src/barrierident.c
librtems_a_SOURCES += src/barriertranslatereturncode.c
librtems_a_SOURCES += src/barrierrelease.c
librtems_a_SOURCES += src/barrierwait.c

## CLOCK_C_FILES
librtems_a_SOURCES += src/clockgetsecondssinceepoch.c
librtems_a_SOURCES += src/clockgettickspersecond.c
librtems_a_SOURCES += src/clockgettod.c
librtems_a_SOURCES += src/clockgettodtimeval.c
librtems_a_SOURCES += src/clockgetuptime.c
librtems_a_SOURCES += src/clockgetuptimetimeval.c
librtems_a_SOURCES += src/clockgetuptimenanoseconds.c
librtems_a_SOURCES += src/clockset.c
librtems_a_SOURCES += src/clocktick.c
librtems_a_SOURCES += src/clocktodtoseconds.c
librtems_a_SOURCES += src/clocktodvalidate.c

## TIMER_C_FILES
librtems_a_SOURCES += src/rtemstimer.c
librtems_a_SOURCES += src/timercancel.c
librtems_a_SOURCES += src/timercreate.c
librtems_a_SOURCES += src/timerdelete.c
librtems_a_SOURCES += src/timerfireafter.c
librtems_a_SOURCES += src/timerfirewhen.c
librtems_a_SOURCES += src/timergetinfo.c
librtems_a_SOURCES += src/timerident.c
librtems_a_SOURCES += src/timerreset.c
librtems_a_SOURCES += src/timerserver.c
librtems_a_SOURCES += src/timerserverfireafter.c
librtems_a_SOURCES += src/timerserverfirewhen.c

## MESSAGE_QUEUE_C_FILES
librtems_a_SOURCES += src/msg.c
librtems_a_SOURCES += src/msgqbroadcast.c
librtems_a_SOURCES += src/msgqcreate.c
librtems_a_SOURCES += src/msgqdelete.c
librtems_a_SOURCES += src/msgqflush.c
librtems_a_SOURCES += src/msgqgetnumberpending.c
librtems_a_SOURCES += src/msgqident.c
librtems_a_SOURCES += src/msgqreceive.c
librtems_a_SOURCES += src/msgqsend.c
librtems_a_SOURCES += src/msgqtranslatereturncode.c
librtems_a_SOURCES += src/msgqurgent.c

## SEMAPHORE_C_FILES
librtems_a_SOURCES += src/sem.c
librtems_a_SOURCES += src/semcreate.c
librtems_a_SOURCES += src/semdelete.c
librtems_a_SOURCES += src/semident.c
librtems_a_SOURCES += src/semobtain.c
librtems_a_SOURCES += src/semrelease.c
librtems_a_SOURCES += src/semflush.c
librtems_a_SOURCES += src/semtranslatereturncode.c
librtems_a_SOURCES += src/semsetpriority.c

## EVENT_C_FILES
librtems_a_SOURCES += src/eventreceive.c
librtems_a_SOURCES += src/eventseize.c
librtems_a_SOURCES += src/eventsend.c
librtems_a_SOURCES += src/eventsurrender.c
librtems_a_SOURCES += src/systemeventsend.c
librtems_a_SOURCES += src/systemeventreceive.c

## SIGNAL_C_FILES
librtems_a_SOURCES += src/signalcatch.c
librtems_a_SOURCES += src/signalsend.c

## REGION_C_FILES
librtems_a_SOURCES += src/region.c
librtems_a_SOURCES += src/regioncreate.c
librtems_a_SOURCES += src/regiondelete.c
librtems_a_SOURCES += src/regionextend.c
librtems_a_SOURCES += src/regiongetsegment.c
librtems_a_SOURCES += src/regiongetsegmentsize.c
librtems_a_SOURCES += src/regionident.c
librtems_a_SOURCES += src/regionreturnsegment.c
librtems_a_SOURCES += src/regiongetinfo.c
librtems_a_SOURCES += src/regiongetfreeinfo.c
librtems_a_SOURCES += src/regionresizesegment.c
librtems_a_SOURCES += src/regionprocessqueue.c

## PARTITION_C_FILES
librtems_a_SOURCES += src/part.c
librtems_a_SOURCES += src/partcreate.c
librtems_a_SOURCES += src/partdelete.c
librtems_a_SOURCES += src/partgetbuffer.c
librtems_a_SOURCES += src/partident.c
librtems_a_SOURCES += src/partreturnbuffer.c

## DPMEM_C_FILES
librtems_a_SOURCES += src/dpmem.c
librtems_a_SOURCES += src/dpmemcreate.c
librtems_a_SOURCES += src/dpmemdelete.c
librtems_a_SOURCES += src/dpmemexternal2internal.c
librtems_a_SOURCES += src/dpmemident.c
librtems_a_SOURCES += src/dpmeminternal2external.c

## WORKSPACE_FILES
librtems_a_SOURCES += src/workspace.c
librtems_a_SOURCES += src/workspacegreedy.c

librtems_a_SOURCES += src/modes.c

librtems_a_SOURCES += src/status.c
librtems_a_SOURCES += src/statustext.c

librtems_a_SOURCES += src/getcurrentprocessor.c
librtems_a_SOURCES += src/getprocessorcount.c

if HAS_MP
# We only build multiprocessing related files if HAS_MP was defined
librtems_a_SOURCES += src/eventmp.c
librtems_a_SOURCES += src/mp.c
librtems_a_SOURCES += src/msgmp.c
librtems_a_SOURCES += src/partmp.c
librtems_a_SOURCES += src/regionmp.c
librtems_a_SOURCES += src/semmp.c
librtems_a_SOURCES += src/signalmp.c
librtems_a_SOURCES += src/taskmp.c
endif

include $(srcdir)/preinstall.am
include $(top_srcdir)/automake/local.am
