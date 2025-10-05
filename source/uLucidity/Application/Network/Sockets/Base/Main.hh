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
#ifndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH

#include "uLucidity/Application/Base/Main.hh"

#include "xos/network/sockets/os/interfaces.hpp"
#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT

namespace uLucidity {
namespace Application {
namespace Network {
namespace Sockets {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template <class TExtends = uLucidity::Application::Base::Main, class TImplements = typename TExtends::Implements>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef Maint Derives, derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::char_t char_t;

    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : Run_(0),
      accept_one_(false), accept_done_(false), accept_restart_(false),
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      relay_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    /// ...Run
    int (derives::*Run_)(string &target, const string &source);
    virtual int Run(string &target, const string &source) {
        int err = 0;
        if (Run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*Run_)(target, source)))...");
            if (!(err = (this->*Run_)(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*Run_)(target, source)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*Run_)(target, source)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_Run(target, source)))...");
            if (!(err = default_Run(target, source))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_Run(target, source)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_Run(target, source)))");
            }
        }
        return err;
    }
    virtual int default_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int before_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int after_Run(string &target, const string &source) {
        int err = 0;
        return err;
    }
public:
    virtual int all_Run(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Run(target, source))) {
            int err2 = 0;
            err = Run(target, source);
            if ((err2 = after_Run(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
protected:

    //////////////////////////////////////////////////////////////////////////
    /// ..host / ..port
    /// ...
    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual const string_t& get_host() const {
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short& set_port(const short& to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }
    virtual const short& get_port() const {
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual const string_t& get_accept_host() const {
        return this->accept_host();
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(const short& to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual const short& get_accept_port() const {
        return this->accept_port();
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one / ...accept_done / ...accept_restart
    virtual bool& set_accept_one(const bool& to) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual const bool& get_accept_one() const {
        return this->accept_one();
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }
    /// ...accept_done
    virtual bool& set_accept_done(const bool& to) {
        bool& accept_done = this->accept_done();
        accept_done = to;
        return accept_done;
    }
    virtual const bool& get_accept_done() const {
        return this->accept_done();
    }
    virtual bool& accept_done() const {
        return (bool&)accept_done_;
    }
    virtual bool& stop_set(const bool& to) {
        bool& stop = this->stop();
        LOGGER_IS_LOGGED_INFO("(true == (stop = " << stop << "))...");
        if (true == (stop)) {
            LOGGER_IS_LOGGED_INFO("...(true == (stop = " << stop << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(stop = " << stop << ")...");
            set_accept_done(stop);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (stop = " << stop << "))");
        }
        return stop;
    }
    /// ...accept_restart
    virtual bool& set_accept_restart(const bool& to) {
        bool& accept_restart = this->accept_restart();
        accept_restart = to;
        return accept_restart;
    }
    virtual const bool& get_accept_restart() const {
        return this->accept_restart();
    }
    virtual bool& accept_restart() const {
        return (bool&)accept_restart_;
    }
    virtual bool& restart_set(const bool& to) {
        bool& restart = this->restart();
        LOGGER_IS_LOGGED_INFO("(true == (restart = " << restart << "))...");
        if (true == (restart)) {
            LOGGER_IS_LOGGED_INFO("...(true == (restart = " << restart << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(restart = " << restart << ")...");
            set_accept_restart(restart);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (restart = " << restart << "))");
        }
        return restart;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual const string_t& get_connect_host() const {
        return this->connect_host();
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(const short& to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual const short& get_connect_port() const {
        return this->connect_port();
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual const string_t& get_relay_host() const {
        return this->relay_host();
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(const short& to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual const short& get_relay_port() const {
        return this->relay_port();
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*connect_ep_)() const;
    virtual xos::network::sockets::endpoint& connect_ep() const {
        if ((this->connect_ep_)) {
            return (this->*connect_ep_)();
        }
        return this->default_connect_ep();
    }
    virtual xos::network::sockets::endpoint& default_connect_ep() const {
        return this->connect_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& connect_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& connect_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*connect_tp_)() const;
    virtual xos::network::sockets::transport& connect_tp() const {
        if ((this->connect_tp_)) {
            return (this->*connect_tp_)();
        }
        return this->default_connect_tp();
    }
    virtual xos::network::sockets::transport& default_connect_tp() const {
        return this->connect_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& connect_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& connect_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...iface / ...addr / ...ep/ ...tp
    /// ...
    /// ...os_iface
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    /// ...
    /// ...iface / ...addr / ...ep/ ...tp
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart / ...stop
    virtual bool& restart() const {
        return (bool&)restart_;
    }
    virtual bool& stop() const {
        return (bool&)stop_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    bool restart_, stop_;
    bool accept_one_, accept_done_, accept_restart_;
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;

    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Sockets 
} /// namespace Network 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_NETWORK_SOCKETS_BASE_MAIN_HH
