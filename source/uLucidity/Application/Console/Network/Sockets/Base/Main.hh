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
#ifndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HH

#include "uLucidity/Application/Console/Network/Sockets/Base/MainOpt.hh"
#include "uLucidity/Application/Network/Sockets/Base/Main.hh"
#include "uLucidity/Application/Network/Sockets/Client/Main.hh"
#include "uLucidity/Application/Network/Sockets/Server/Main.hh"

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_REQUEST \
    "{\"password\":{\"user\":\"user\",\"resource\":\"resource\",\"password\":\"password\"}}"

#define ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_RESPONSE \
    "{\"password\":\"unknown\"}"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Network {
namespace Sockets {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TExtends = uLucidity::Application::Console::Network::Sockets::Base::MainOpt, 
 class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef uLucidity::Application::Network::Sockets::Base::Main::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::string_t::char_t char_t;
    
    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : request_(ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_REQUEST),
      response_(ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_UDENTIFY_DEFAULT_RESPONSE) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = main_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))...");
        if (!(err = main_.all_Run(response_, request_))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = main_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = main_.all_Run(response_ = \"" << response_ << "\", request_ = \"" << request_ << "\")))");
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
protected:
    string request_, response_;
    uLucidity::Application::Network::Sockets::Client::Main main_;
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HH
