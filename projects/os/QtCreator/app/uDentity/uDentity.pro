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
#   File: uDentity.pro
#
# Author: $author$
#   Date: 11/1/2022
#
# os specific QtCreator project .pro file for framework uLucidity executable uDentity
########################################################################
#
# Debug: uLucidity/build/os/QtCreator/Debug/bin/uDentity
# Release: uLucidity/build/os/QtCreator/Release/bin/uDentity
# Profile: uLucidity/build/os/QtCreator/Profile/bin/uDentity
#
include(../../../../../build/QtCreator/uLucidity.pri)
include(../../../../QtCreator/uLucidity.pri)
include(../../uLucidity.pri)
include(../../../../QtCreator/app/uDentity/uDentity.pri)

TARGET = $${uDentity_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${uDentity_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${uDentity_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${uDentity_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${uDentity_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${uDentity_HEADERS} \
$${uDentity_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${uDentity_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${uDentity_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${uDentity_LIBS} \
$${FRAMEWORKS} \

########################################################################

