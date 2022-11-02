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
# os specific QtCreator project .pri file for framework uLucidity
########################################################################

UNAME = $$system(uname)

contains(UNAME,Darwin) {
DARWIN_VERSION = $$system(sw_vers -productVersion)
} else {
contains(UNAME,Linux) {
LINUX_VERSION = $$system(uname -r)
} else {
contains(UNAME,Windows) {
WINDOWS_VERSION = $$system(ver)
} else {
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
contains(DARWIN_VERSION,11.5.1) {
DARWIN_VERSION_NAME = Bigsur
DARWIN_VERSION_NUMBER = 11+
} else {
contains(DARWIN_VERSION,10.12.6) {
DARWIN_VERSION_NAME = Sierra
DARWIN_VERSION_NUMBER = 10+
} else {
DARWIN_VERSION_NAME = Mavricks
DARWIN_VERSION_NUMBER = 9+
} # contains(DARWIN_VERSION,10.12.6)
} # contains(DARWIN_VERSION,11.5.1)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
ULUCIDITY_OS = macosx
} else {
contains(UNAME,Linux) {
ULUCIDITY_OS = linux
} else {
ULUCIDITY_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,ULUCIDITY_OS) {
ULUCIDITY_BUILD = $${ULUCIDITY_OS}
} else {
ULUCIDITY_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,ULUCIDITY_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(ULUCIDITY_OS,macosx) {
contains(DARWIN_VERSION_NUMBER,11+) {
QMAKE_CFLAGS += -Wno-implicit-function-declaration
} # contains(DARWIN_VERSION_NUMBER,11+)
} else {
contains(ULUCIDITY_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(ULUCIDITY_OS,windows) {
} else {
} # contains(ULUCIDITY_OS,windows)
} # contains(ULUCIDITY_OS,linux)
} # contains(ULUCIDITY_OS,macosx)
########################################################################
# uLucidity

# uLucidity INCLUDEPATH
#
uLucidity_INCLUDEPATH += \

# uLucidity DEFINES
#
uLucidity_DEFINES += \

# uLucidity os LIBS
#
contains(ULUCIDITY_OS,macosx|linux) {
uLucidity_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(ULUCIDITY_OS,macosx|linux)

contains(ULUCIDITY_OS,linux) {
uLucidity_os_LIBS += \
-lrt
} else {
} # contains(ULUCIDITY_OS,linux)


# uLucidity base LIBS
#
uLucidity_base_LIBS += \


# uLucidity LIBS
#
uLucidity_LIBS += \
$${uLucidity_base_LIBS} \
$${build_uLucidity_LIBS} \
$${uLucidity_os_LIBS} \

# uLucidity cocoa LIBS
#
uLucidity_cocoa_LIBS += \
$${uLucidity_LIBS} \

contains(ULUCIDITY_OS,macosx) {
uLucidity_cocoa_LIBS += \
-framework AppKit \
-framework CoreFoundation \
-framework Foundation \
} else {
} # contains(ULUCIDITY_OS,macosx)
