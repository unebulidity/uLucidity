///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: DLibraryMain.cpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#include "uLucidity/OS/Apple/Osx/DLibraryMain.hpp"
#include "uLucidity/OS/Posix/DLibraryMain.cpp"

namespace uLucidity {
namespace OS {
namespace Apple {
namespace Osx {

///////////////////////////////////////////////////////////////////////
///  Class: DLibraryMain
///////////////////////////////////////////////////////////////////////

} // namespace Osx 
} // namespace Apple 
} // namespace OS 
} // namespace uLucidity 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void __attribute__ ((constructor)) _apple_osx_init(void) {
    STDERR_LOG_DEBUG("_init()...");
    _init();
}
void __attribute__ ((destructor)) _apple_osx_fini(void) {
    STDERR_LOG_DEBUG("_fini()...");
    _fini();
}
