include $(top_srcdir)/automake/multilib.am
include $(top_srcdir)/automake/compile.am

include_rtemsdir = $(includedir)/rtems

include_rtems_HEADERS = include/confdefs.h
include_rtems_HEADERS += include/rtems/bsd.h
include_rtems_HEADERS += include/rtems/chain.h
include_rtems_HEADERS += include/rtems/config.h
include_rtems_HEADERS += include/rtems/counter.h
include_rtems_HEADERS += include/rtems/extension.h
include_rtems_HEADERS += include/rtems/extensionimpl.h
include_rtems_HEADERS += include/rtems/fatal.h
include_rtems_HEADERS += include/rtems/init.h
include_rtems_HEADERS += include/rtems/io.h
include_rtems_HEADERS += include/rtems/ioimpl.h
include_rtems_HEADERS += include/rtems/mptables.h
include_rtems_HEADERS += include/rtems/cbs.h
include_rtems_HEADERS += include/rtems/profiling.h
include_rtems_HEADERS += include/rtems/rbheap.h
include_rtems_HEADERS += include/rtems/rbtree.h
include_rtems_HEADERS += include/rtems/scheduler.h
include_rtems_HEADERS += include/rtems/timecounter.h
include_rtems_HEADERS += include/rtems/timespec.h

EXTRA_DIST = include/rtems/README

noinst_LIBRARIES = libsapi.a
libsapi_a_SOURCES = src/extension.c src/extensioncreate.c \
    src/extensiondelete.c src/extensionident.c src/fatal.c src/exinit.c \
    src/exshutdown.c src/io.c src/ioclose.c src/iocontrol.c \
    src/ioinitialize.c src/ioopen.c src/ioread.c src/ioregisterdriver.c \
    src/iounregisterdriver.c src/iowrite.c src/posixapi.c  \
    src/getversionstring.c \
    src/chainappendnotify.c src/chaingetnotify.c src/chaingetwait.c \
    src/chainprependnotify.c src/rbheap.c src/interrtext.c \
    src/fatal2.c src/fatalsrctext.c
libsapi_a_SOURCES += src/chainprotected.c
libsapi_a_SOURCES += src/cpucounterconverter.c
libsapi_a_SOURCES += src/delayticks.c
libsapi_a_SOURCES += src/delaynano.c
libsapi_a_SOURCES += src/rbtree.c
libsapi_a_SOURCES += src/profilingiterate.c
libsapi_a_SOURCES += src/profilingreportxml.c
libsapi_a_SOURCES += src/tcsimpleinstall.c
libsapi_a_CPPFLAGS = $(AM_CPPFLAGS)

include $(srcdir)/preinstall.am
include $(top_srcdir)/automake/local.am
