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
# generic QtCreator project .pri file for framework uLucidity
########################################################################

OTHER_RPO = ../../../../../../..
OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}


########################################################################
# uLucidity
ULUCIDITY_NAME = uLucidity
ULUCIDITY_SOURCE = source
ULUCIDITY_CREDS = creds

ULUCIDITY_PKG = ../../../../..
ULUCIDITY_BLD = ../..

ULUCIDITY_PRJ = $${ULUCIDITY_PKG}
ULUCIDITY_BIN = $${ULUCIDITY_BLD}/bin
ULUCIDITY_LIB = $${ULUCIDITY_BLD}/lib
ULUCIDITY_SRC = $${ULUCIDITY_PKG}/$${ULUCIDITY_SOURCE}
ULUCIDITY_CRD_SRC = $${ULUCIDITY_PKG}/$${ULUCIDITY_CREDS}/$${ULUCIDITY_SOURCE}

# uLucidity BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
uLucidity_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
uLucidity_DEFINES += RELEASE_BUILD
}

# uLucidity INCLUDEPATH
#
uLucidity_INCLUDEPATH += \
$${ULUCIDITY_SRC} \
$${ULUCIDITY_CRD_SRC} \
$${build_uLucidity_INCLUDEPATH} \

# uLucidity DEFINES
#
uLucidity_DEFINES += \
$${build_uLucidity_DEFINES} \

# uLucidity LIBS
#
uLucidity_LIBS += \
-L$${ULUCIDITY_LIB}/lib$${ULUCIDITY_NAME} \
-l$${ULUCIDITY_NAME} \

# uLucidity xos LIBS
#
NADIR_NAME = nadir
uLucidity_xos_LIBS += \
$${uLucidity_LIBS} \
-L$${ULUCIDITY_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \
