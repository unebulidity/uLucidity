//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Main.hh
///
/// Author: $author$
///   Date: 10/5/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_BASE_MAIN_HH

#include "uLucidity/Base/Base.hh"
#include "xos/base/string.hpp"
#include "xos/base/logger.hpp"

#define LOG_ANY   LOGGER_LOG_ANY  
#define LOG_FATAL LOGGER_LOG_FATAL
#define LOG_ERROR LOGGER_LOG_ERROR
#define LOG_WARN  LOGGER_LOG_WARN 
#define LOG_INFO  LOGGER_LOG_INFO 
#define LOG_DEBUG LOGGER_LOG_DEBUG
#define LOG_TRACE LOGGER_LOG_TRACE

namespace uLucidity {
namespace Application {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template <class TExtends = uLucidity::Base, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef xos::base::string string;
    typedef xos::base::string string_t;
    typedef xos::base::string::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_BASE_MAIN_HH

