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
#   File: libuDentityPlugin.pri
#
# Author: $author$
#   Date: 11/2/2022
#
# generic QtCreator project .pri file for framework uLucidity shared library libuDentityPlugin
########################################################################

########################################################################
# libuDentityPlugin

# libuDentityPlugin TARGET
#
libuDentityPlugin_TARGET = uDentityPlugin
libuDentityPlugin_TEMPLATE = lib

# libuDentityPlugin INCLUDEPATH
#
libuDentityPlugin_INCLUDEPATH += \
$${uLucidity_INCLUDEPATH} \

# libuDentityPlugin DEFINES
#
libuDentityPlugin_DEFINES += \
$${uLucidity_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libuDentityPlugin OBJECTIVE_HEADERS
#
libuDentityPlugin_OBJECTIVE_HEADERS += \

# libuDentityPlugin OBJECTIVE_SOURCES
#
libuDentityPlugin_OBJECTIVE_SOURCES += \

########################################################################
# libuDentityPlugin HEADERS
#
libuDentityPlugin_HEADERS += \
$${ULUCIDITY_SRC}/uLucidity/UI/ThePlugin.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/Plugin.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/PluginSignals.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/PluginMain.hpp \
$${ULUCIDITY_SRC}/uLucidity/OS/DLibraryMain.hpp \
$${ULUCIDITY_SRC}/uLucidity/OS/OS.hpp \

# libuDentityPlugin SOURCES
#
libuDentityPlugin_SOURCES += \
$${ULUCIDITY_SRC}/uLucidity/UI/ThePlugin.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/PluginMain.cpp \
$${ULUCIDITY_SRC}/uLucidity/OS/DLibraryMain.cpp \

########################################################################
# libuDentityPlugin FRAMEWORKS
#
libuDentityPlugin_FRAMEWORKS += \
$${uLucidity_FRAMEWORKS} \

# libuDentityPlugin LIBS
#
libuDentityPlugin_LIBS += \
$${uLucidity_LIBS} \

########################################################################
# NO Qt
QT -= gui core

