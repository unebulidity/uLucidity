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
#   File: libuLucidity.pri
#
# Author: $author$
#   Date: 11/1/2022
#
# generic QtCreator project .pri file for framework uLucidity static library libuLucidity
########################################################################

########################################################################
# libuLucidity
XOS_LIB_ULUCIDITY_VERSION_BUILD_DATE = 11/1/2022 #$$system(~/bin/utility/tdate)

# libuLucidity TARGET
#
libuLucidity_TARGET = uLucidity
libuLucidity_TEMPLATE = lib
libuLucidity_CONFIG += staticlib

# libuLucidity INCLUDEPATH
#
libuLucidity_INCLUDEPATH += \
$${uLucidity_INCLUDEPATH} \

# libuLucidity DEFINES
#
libuLucidity_DEFINES += \
$${uLucidity_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_ULUCIDITY_VERSION_BUILD_DATE=$${XOS_LIB_ULUCIDITY_VERSION_BUILD_DATE} \

########################################################################
# libuLucidity OBJECTIVE_HEADERS
#
#libuLucidity_OBJECTIVE_HEADERS += \
#$${ULUCIDITY_SRC}/xos/lib/uLucidity/version.hh \

# libuLucidity OBJECTIVE_SOURCES
#
#libuLucidity_OBJECTIVE_SOURCES += \
#$${ULUCIDITY_SRC}/xos/lib/uLucidity/version.mm \

########################################################################
# libuLucidity HEADERS
#
libuLucidity_HEADERS += \
$${ULUCIDITY_SRC}/xos/lib/uLucidity/version.hpp \

# libuLucidity SOURCES
#
libuLucidity_SOURCES += \
$${ULUCIDITY_SRC}/xos/lib/uLucidity/version.cpp \

########################################################################

