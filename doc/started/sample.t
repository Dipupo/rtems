@c
@c  COPYRIGHT (c) 1988-1999.
@c  On-Line Applications Research Corporation (OAR).
@c  All rights reserved.
@c
@c  $Id$
@c

@chapter Building the Sample Application

@section Unpack the Sample Application 

Use the following command to unarchive the sample application:

@example
cd tools
tar xzf ../archive/hello_world_c.tgz
@end example

@section Set the Environment Variable RTEMS_MAKEFILE_PATH 

It must point to the appropriate directory containing RTEMS build for our
target and board support package combination. 

@example
export RTEMS_MAKEFILE_PATH = <INSTALLATION_POINT>/<BOARD_SUPPORT_PACKAGE>
@end example

Where <INSTALLATION_POINT> and <BOARD_SUPPORT_PACKAGE> are those used when
configuring and installing RTEMS.

NOTE:  In release 4.0, BSPs were installed at
@code{<INSTALLATION_POINT>/rtems/<BOARD_SUPPORT_PACKAGE>}.  This
was changed to be more in compliance with GNU standards.

@section Build the Sample Application

Use the following command to start the build of the sample application: 

@example
cd tools/hello_world_c
make
@end example

NOTE: GNU make is the preferred @code{make} utility.  Other @code{make}
implementations may work but all testing is done with GNU make.

If no errors are detected during the sample application build, it is
reasonable to assume that the build of the GNU C/C++ Cross Compiler Tools
for RTEMS and RTEMS itself for the selected host and target
combination was done properly. 

@section Application Executable 

If the sample application has successfully been build, then the application
executable is placed in the following directory: 

@example
tools/hello_world_c/o-optimize/<filename>.exe
@end example

How this executable is downloaded to the target board is very dependent
on the BOARD_SUPPORT_PACKAGE selected.

@section More Information on RTEMS Application Makefiles

The hello world sample application is a simple example of an
RTEMS application the uses the RTEMS Application Makefile 
system.  This Makefile system gives simplifies building
RTEMS applications by providing Makefile templates and
capturing the configuration information used to build
RTEMS specific to your BSP.  Building an RTEMS application
for different BSPs is as simple as switching the
setting of @code{RTEMS_MAKEFILE_PATH}.  This Makefile
system is described in the file
@code{@value{RTEMS-UNTAR}/make/README}.
