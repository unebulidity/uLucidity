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
#   File: libuDentityPlugin.pro
#
# Author: $author$
#   Date: 11/2/2022
#
# os specific QtCreator project .pro file for framework uLucidity shared library libuDentityPlugin
########################################################################
#
# Debug: uLucidity/build/os/QtCreator/Debug/lib/libuDentityPlugin
# Release: uLucidity/build/os/QtCreator/Release/lib/libuDentityPlugin
# Profile: uLucidity/build/os/QtCreator/Profile/lib/libuDentityPlugin
#
include(../../../../../build/QtCreator/uLucidity.pri)
include(../../../../QtCreator/uLucidity.pri)
include(../../uLucidity.pri)
include(../../../../QtCreator/lib/libuDentityPlugin/libuDentityPlugin.pri)

TARGET = $${libuDentityPlugin_TARGET}
TEMPLATE = $${libuDentityPlugin_TEMPLATE}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libuDentityPlugin_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libuDentityPlugin_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libuDentityPlugin_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libuDentityPlugin_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libuDentityPlugin_HEADERS} \
$${libuDentityPlugin_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libuDentityPlugin_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${libuDentityPlugin_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${libuDentityPlugin_LIBS} \
$${FRAMEWORKS} \

########################################################################

