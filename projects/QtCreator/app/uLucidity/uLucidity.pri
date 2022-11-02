########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: uLucidity.pri
#
# Author: $author$
#   Date: 11/1/2022
#
# generic QtCreator project .pri file for framework uLucidity executable uLucidity
########################################################################

########################################################################
# uLucidity

# uLucidity_exe TARGET
#
uLucidity_exe_TARGET = uLucidity

# uLucidity_exe INCLUDEPATH
#
uLucidity_exe_INCLUDEPATH += \
$${uLucidity_INCLUDEPATH} \

# uLucidity_exe DEFINES
#
uLucidity_exe_DEFINES += \
$${uLucidity_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# uLucidity_exe OBJECTIVE_HEADERS
#
#uLucidity_exe_OBJECTIVE_HEADERS += \
#$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main.hh \

# uLucidity_exe OBJECTIVE_SOURCES
#
#uLucidity_exe_OBJECTIVE_SOURCES += \
#$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main.mm \

########################################################################
# uLucidity_exe HEADERS
#
uLucidity_exe_HEADERS += \
$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main_opt.hpp \
$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main.hpp \

# uLucidity_exe SOURCES
#
uLucidity_exe_SOURCES += \
$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main_opt.cpp \
$${ULUCIDITY_SRC}/xos/app/console/uLucidity/main.cpp \

########################################################################
# uLucidity_exe FRAMEWORKS
#
uLucidity_exe_FRAMEWORKS += \
$${uLucidity_xos_FRAMEWORKS} \

# uLucidity_exe LIBS
#
uLucidity_exe_LIBS += \
$${uLucidity_xos_LIBS} \

########################################################################
# NO Qt
QT -= gui core

