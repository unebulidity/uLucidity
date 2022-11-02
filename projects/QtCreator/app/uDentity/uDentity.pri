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
#   File: uDentity.pri
#
# Author: $author$
#   Date: 11/1/2022
#
# generic QtCreator project .pri file for framework uLucidity executable uDentity
########################################################################

########################################################################
# uDentity

# uDentity TARGET
#
uDentity_TARGET = uDentity

# uDentity INCLUDEPATH
#
uDentity_INCLUDEPATH += \
$${uLucidity_INCLUDEPATH} \

# uDentity DEFINES
#
uDentity_DEFINES += \
$${uLucidity_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# uDentity OBJECTIVE_HEADERS
#
uDentity_OBJECTIVE_HEADERS += \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/GraphicSurface/GraphicContext.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/GraphicSurface/GraphicPixel.hh \
\
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Main.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Window.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/View.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Content.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Button.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Menu.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/MenuItem.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Signals.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Images.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Image.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Logger.hh \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Cocoa.hh \

# uDentity OBJECTIVE_SOURCES
#
uDentity_OBJECTIVE_SOURCES += \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/GraphicSurface/GraphicContext.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/GraphicSurface/GraphicPixel.mm \
\
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Main.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Window.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/View.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Content.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Button.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Menu.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/MenuItem.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Images.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Image.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Signals.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Logger.mm \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Cocoa.mm \

########################################################################
# uDentity HEADERS
#
uDentity_HEADERS += \
$${ULUCIDITY_SRC}/uLucidity/Platform/Platform.h \
$${ULUCIDITY_SRC}/uLucidity/Platform/PlatformBuild.h \
$${ULUCIDITY_SRC}/uLucidity/Platform/PlatformCompiler.h \
$${ULUCIDITY_SRC}/uLucidity/Platform/PlatformIncludes.h \
$${ULUCIDITY_SRC}/uLucidity/Platform/PlatformDefines.h \
$${ULUCIDITY_SRC}/uLucidity/Platform/PlatformTypes.h \
\
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageBase.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImage.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageFormat.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageInterpolation.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/ColorChannel.hpp \
\
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicSurface/GraphicContext.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicSurface/GraphicPixel.hpp \
\
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/DefaultHandlers.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Handlers.hpp \
\
$${ULUCIDITY_SRC}/uLucidity/UI/PluginLibrary.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/Plugin.hpp \
$${ULUCIDITY_SRC}/uLucidity/UI/PluginSignals.hpp \
$${ULUCIDITY_SRC}/uLucidity/OS/DLibrary.hpp \
$${ULUCIDITY_SRC}/uLucidity/OS/OS.hpp \

# uDentity SOURCES
#
uDentity_SOURCES += \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageBase.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImage.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageFormat.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/GraphicImageInterpolation.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/ColorChannel.cpp \
\
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/DefaultHandlers.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/Cocoa/Handlers.cpp \
\
$${ULUCIDITY_SRC}/uLucidity/UI/PluginLibrary.cpp \
$${ULUCIDITY_SRC}/uLucidity/UI/Plugin.cpp \
$${ULUCIDITY_SRC}/uLucidity/OS/DLibrary.cpp \
$${ULUCIDITY_SRC}/uLucidity/OS/OS.cpp \

########################################################################
# uDentity FRAMEWORKS
#
uDentity_FRAMEWORKS += \
$${uLucidity_cocoa_FRAMEWORKS} \

# uDentity LIBS
#
uDentity_LIBS += \
$${uLucidity_cocoa_LIBS} \

########################################################################
# NO Qt
QT -= gui core
