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
///   Date: 10/8/2025
//////////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_APPLICATION_CONSOLE_PROTOCOL_BASE_MAIN_HH
#define ULUCIDITY_APPLICATION_CONSOLE_PROTOCOL_BASE_MAIN_HH

#include "uLucidity/Application/Console/Protocol/Base/MainOpt.hh"

namespace uLucidity {
namespace Application {
namespace Console {
namespace Protocol {
namespace Base {

//////////////////////////////////////////////////////////////////////////
/// class Maint
template 
<class TExtends = uLucidity::Application::Console::Protocol::Base::MainOpt, class TImplements = typename TExtends::Implements>
class exported Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef Maint Derives;

    typedef typename Extends::string string;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::string_t::char_t char_t;
    
    //////////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    Maint()
    : udentity_path_("doc/udentify/udentity"),
      
      valueof_unknown_udentify_user_("unknown"), 
      valueof_unknown_udentify_resource_(valueof_unknown_udentify_user_), 
      valueof_unknown_udentify_password_(valueof_unknown_udentify_user_),

      nameof_udentify_user_("user"), 
      nameof_udentify_resource_("resource"), 
      nameof_udentify_password_("password"),

      default_udentify_user_(nameof_udentify_user_), 
      default_udentify_resource_(nameof_udentify_resource_), 
      default_udentify_password_(nameof_udentify_password_),

      udentify_user_(default_udentify_user_), 
      udentify_resource_(default_udentify_resource_), 
      udentify_password_(default_udentify_password_),

      begin_udentify_resource_("\",\"resource\":\""), 
      begin_udentify_password_("\",\"password\":\""),
      begin_udentify_message_("{\"password\":{\"user\":\""), 
      endof_udentify_message_("\"}}"),

      begin_udentify_response_message_("{\"password\":\""), 
      endof_udentify_response_message_("\"}") {
        set_default_udentify_request_message();
        set_default_udentify_response_message();
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy): Extends(copy) {
    }
public:
protected:

    //////////////////////////////////////////////////////////////////////////
    /// ...valueof_unknown_udentify_user
    virtual string_t& set_valueof_unknown_udentify_user(const string_t& to) {
        string_t& valueof_unknown_udentify_user = this->valueof_unknown_udentify_user();
        valueof_unknown_udentify_user.assign(to);
        return valueof_unknown_udentify_user;
    }
    virtual string_t& set_valueof_unknown_udentify_user(const char_t* to) {
        string_t& valueof_unknown_udentify_user = this->valueof_unknown_udentify_user();
        valueof_unknown_udentify_user.assign(to);
        return valueof_unknown_udentify_user;
    }
    virtual string_t& valueof_unknown_udentify_user() const {
        return (string_t&)valueof_unknown_udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...valueof_unknown_udentify_resource
    virtual string_t& set_valueof_unknown_udentify_resource(const string_t& to) {
        string_t& valueof_unknown_udentify_resource = this->valueof_unknown_udentify_resource();
        valueof_unknown_udentify_resource.assign(to);
        return valueof_unknown_udentify_resource;
    }
    virtual string_t& set_valueof_unknown_udentify_resource(const char_t* to) {
        string_t& valueof_unknown_udentify_resource = this->valueof_unknown_udentify_resource();
        valueof_unknown_udentify_resource.assign(to);
        return valueof_unknown_udentify_resource;
    }
    virtual string_t& valueof_unknown_udentify_resource() const {
        return (string_t&)valueof_unknown_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...valueof_unknown_udentify_password
    virtual string_t& set_valueof_unknown_udentify_password(const string_t& to) {
        string_t& valueof_unknown_udentify_password = this->valueof_unknown_udentify_password();
        valueof_unknown_udentify_password.assign(to);
        return valueof_unknown_udentify_password;
    }
    virtual string_t& set_valueof_unknown_udentify_password(const char_t* to) {
        string_t& valueof_unknown_udentify_password = this->valueof_unknown_udentify_password();
        valueof_unknown_udentify_password.assign(to);
        return valueof_unknown_udentify_password;
    }
    virtual string_t& valueof_unknown_udentify_password() const {
        return (string_t&)valueof_unknown_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_user
    virtual string_t& set_nameof_udentify_user(const string_t& to) {
        string_t& nameof_udentify_user = this->nameof_udentify_user();
        nameof_udentify_user.assign(to);
        return nameof_udentify_user;
    }
    virtual string_t& set_nameof_udentify_user(const char_t* to) {
        string_t& nameof_udentify_user = this->nameof_udentify_user();
        nameof_udentify_user.assign(to);
        return nameof_udentify_user;
    }
    virtual string_t& nameof_udentify_user() const {
        return (string_t&)nameof_udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_resource
    virtual string_t& set_nameof_udentify_resource(const string_t& to) {
        string_t& nameof_udentify_resource = this->nameof_udentify_resource();
        nameof_udentify_resource.assign(to);
        return nameof_udentify_resource;
    }
    virtual string_t& set_nameof_udentify_resource(const char_t* to) {
        string_t& nameof_udentify_resource = this->nameof_udentify_resource();
        nameof_udentify_resource.assign(to);
        return nameof_udentify_resource;
    }
    virtual string_t& nameof_udentify_resource() const {
        return (string_t&)nameof_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_password
    virtual string_t& set_nameof_udentify_password(const string_t& to) {
        string_t& nameof_udentify_password = this->nameof_udentify_password();
        nameof_udentify_password.assign(to);
        return nameof_udentify_password;
    }
    virtual string_t& set_nameof_udentify_password(const char_t* to) {
        string_t& nameof_udentify_password = this->nameof_udentify_password();
        nameof_udentify_password.assign(to);
        return nameof_udentify_password;
    }
    virtual string_t& nameof_udentify_password() const {
        return (string_t&)nameof_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_user
    virtual string_t& set_default_udentify_user(const string_t& to) {
        string_t& default_udentify_user = this->default_udentify_user();
        default_udentify_user.assign(to);
        return set_udentify_user(to);
    }
    virtual string_t& set_default_udentify_user(const char_t* to) {
        string_t& default_udentify_user = this->default_udentify_user();
        default_udentify_user.assign(to);
        return set_udentify_user(to);
    }
    virtual string_t& default_udentify_user() const {
        return (string_t&)default_udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_resource
    virtual string_t& set_default_udentify_resource(const string_t& to) {
        string_t& default_udentify_resource = this->default_udentify_resource();
        default_udentify_resource.assign(to);
        return set_udentify_resource(to);
    }
    virtual string_t& set_default_udentify_resource(const char_t* to) {
        string_t& default_udentify_resource = this->default_udentify_resource();
        default_udentify_resource.assign(to);
        return set_udentify_resource(to);
    }
    virtual string_t& default_udentify_resource() const {
        return (string_t&)default_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_password
    virtual string_t& set_default_udentify_password(const string_t& to) {
        string_t& default_udentify_password = this->default_udentify_password();
        default_udentify_password.assign(to);
        return set_udentify_password(to);
    }
    virtual string_t& set_default_udentify_password(const char_t* to) {
        string_t& default_udentify_password = this->default_udentify_password();
        default_udentify_password.assign(to);
        return set_udentify_password(to);
    }
    virtual string_t& default_udentify_password() const {
        return (string_t&)default_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_user
    virtual string_t& set_udentify_user(const string_t& to) {
        string_t& udentify_user = this->udentify_user();
        udentify_user.assign(to);
        return udentify_user;
    }
    virtual string_t& set_udentify_user(const char_t* to) {
        string_t& udentify_user = this->udentify_user();
        udentify_user.assign(to);
        return udentify_user;
    }
    virtual string_t& udentify_user() const {
        return (string_t&)udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_resource
    virtual string_t& set_udentify_resource(const string_t& to) {
        string_t& udentify_resource = this->udentify_resource();
        udentify_resource.assign(to);
        return udentify_resource;
    }
    virtual string_t& set_udentify_resource(const char_t* to) {
        string_t& udentify_resource = this->udentify_resource();
        udentify_resource.assign(to);
        return udentify_resource;
    }
    virtual string_t& udentify_resource() const {
        return (string_t&)udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_password
    virtual string_t& set_udentify_password(const string_t& to) {
        string_t& udentify_password = this->udentify_password();
        udentify_password.assign(to);
        return udentify_password;
    }
    virtual string_t& set_udentify_password(const char_t* to) {
        string_t& udentify_password = this->udentify_password();
        udentify_password.assign(to);
        return udentify_password;
    }
    virtual string_t& udentify_password() const {
        return (string_t&)udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_resource
    virtual string_t& set_begin_udentify_resource(const string_t& to) {
        string_t& begin_udentify_resource = this->begin_udentify_resource();
        begin_udentify_resource.assign(to);
        return begin_udentify_resource;
    }
    virtual string_t& set_begin_udentify_resource(const char_t* to) {
        string_t& begin_udentify_resource = this->begin_udentify_resource();
        begin_udentify_resource.assign(to);
        return begin_udentify_resource;
    }
    virtual string_t& begin_udentify_resource() const {
        return (string_t&)begin_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_password
    virtual string_t& set_begin_udentify_password(const string_t& to) {
        string_t& begin_udentify_password = this->begin_udentify_password();
        begin_udentify_password.assign(to);
        return begin_udentify_password;
    }
    virtual string_t& set_begin_udentify_password(const char_t* to) {
        string_t& begin_udentify_password = this->begin_udentify_password();
        begin_udentify_password.assign(to);
        return begin_udentify_password;
    }
    virtual string_t& begin_udentify_password() const {
        return (string_t&)begin_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_message
    virtual string_t& set_begin_udentify_message(const string_t& to) {
        string_t& begin_udentify_message = this->begin_udentify_message();
        begin_udentify_message.assign(to);
        return begin_udentify_message;
    }
    virtual string_t& set_begin_udentify_message(const char_t* to) {
        string_t& begin_udentify_message = this->begin_udentify_message();
        begin_udentify_message.assign(to);
        return begin_udentify_message;
    }
    virtual string_t& begin_udentify_message() const {
        return (string_t&)begin_udentify_message_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...endof_udentify_message
    virtual string_t& set_endof_udentify_message(const string_t& to) {
        string_t& endof_udentify_message = this->endof_udentify_message();
        endof_udentify_message.assign(to);
        return endof_udentify_message;
    }
    virtual string_t& set_endof_udentify_message(const char_t* to) {
        string_t& endof_udentify_message = this->endof_udentify_message();
        endof_udentify_message.assign(to);
        return endof_udentify_message;
    }
    virtual string_t& endof_udentify_message() const {
        return (string_t&)endof_udentify_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_response_message
    virtual string_t& set_begin_udentify_response_message(const string_t& to) {
        string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        begin_udentify_response_message.assign(to);
        return begin_udentify_response_message;
    }
    virtual string_t& set_begin_udentify_response_message(const char_t* to) {
        string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        begin_udentify_response_message.assign(to);
        return begin_udentify_response_message;
    }
    virtual string_t& begin_udentify_response_message() const {
        return (string_t&)begin_udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...endof_udentify_response_message
    virtual string_t& set_endof_udentify_response_message(const string_t& to) {
        string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        endof_udentify_response_message.assign(to);
        return endof_udentify_response_message;
    }
    virtual string_t& set_endof_udentify_response_message(const char_t* to) {
        string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        endof_udentify_response_message.assign(to);
        return endof_udentify_response_message;
    }
    virtual string_t& endof_udentify_response_message() const {
        return (string_t&)endof_udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_request_message
    virtual string_t& set_default_udentify_request_message() {
        const string_t& udentify_user = this->default_udentify_user();
        const string_t& udentify_resource = this->default_udentify_resource();
        const string_t& udentify_password = this->default_udentify_password();
        const string_t& begin_udentify_resource = this->begin_udentify_resource();
        const string_t& begin_udentify_password = this->begin_udentify_password();
        const string_t& begin_udentify_message = this->begin_udentify_message();
        const string_t& endof_udentify_message = this->endof_udentify_message();
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(begin_udentify_message);
        udentify_request_message.append(udentify_user);
        udentify_request_message.append(begin_udentify_resource);
        udentify_request_message.append(udentify_resource);
        udentify_request_message.append(begin_udentify_password);
        udentify_request_message.append(udentify_password);
        udentify_request_message.append(endof_udentify_message);
        return udentify_request_message;
    }
    virtual string_t& set_udentify_request_message() {
        const string_t& udentify_user = this->udentify_user();
        const string_t& udentify_resource = this->udentify_resource();
        const string_t& udentify_password = this->udentify_password();
        const string_t& begin_udentify_resource = this->begin_udentify_resource();
        const string_t& begin_udentify_password = this->begin_udentify_password();
        const string_t& begin_udentify_message = this->begin_udentify_message();
        const string_t& endof_udentify_message = this->endof_udentify_message();
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(begin_udentify_message);
        udentify_request_message.append(udentify_user);
        udentify_request_message.append(begin_udentify_resource);
        udentify_request_message.append(udentify_resource);
        udentify_request_message.append(begin_udentify_password);
        udentify_request_message.append(udentify_password);
        udentify_request_message.append(endof_udentify_message);
        return udentify_request_message;
    }
    virtual string_t& set_udentify_request_message(const string_t& to) {
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(to);
        return udentify_request_message;
    }
    virtual string_t& set_udentify_request_message(const char_t* to) {
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(to);
        return udentify_request_message;
    }
    virtual string_t& udentify_request_message() const {
        return (string_t&)udentify_request_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_response_message
    virtual string_t& set_default_udentify_response_message() {
        const string_t& udentify_password = this->valueof_unknown_udentify_password();
        const string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        const string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(begin_udentify_response_message);
        udentify_response_message.append(udentify_password);
        udentify_response_message.append(endof_udentify_response_message);
        return udentify_response_message;
    }
    virtual string_t& set_udentify_response_message() {
        const string_t& udentify_password = this->udentify_password();
        const string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        const string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(begin_udentify_response_message);
        udentify_response_message.append(udentify_password);
        udentify_response_message.append(endof_udentify_response_message);
        return udentify_response_message;
    }
    virtual string_t& set_udentify_response_message(const string_t& to) {
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(to);
        return udentify_response_message;
    }
    virtual string_t& set_udentify_response_message(const char_t* to) {
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(to);
        return udentify_response_message;
    }
    virtual string_t& udentify_response_message() const {
        return (string_t&)udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentity_path
    virtual string_t& set_udentity_path(const string_t& to) {
        string_t& udentity_path = this->udentity_path();
        udentity_path.assign(to);
        return udentity_path;
    }
    virtual string_t& set_udentity_path(const char_t* to) {
        string_t& udentity_path = this->udentity_path();
        udentity_path.assign(to);
        return udentity_path;
    }
    virtual string_t& udentity_path() const {
        return (string_t&)udentity_path_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request...
    virtual string_t& request_message() const {
        return udentify_request_message();
    }
    /// ...response...
    virtual string_t& response_message() const {
        return udentify_response_message();
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t udentity_path_, 
             valueof_unknown_udentify_user_, valueof_unknown_udentify_resource_, valueof_unknown_udentify_password_,
             nameof_udentify_user_, nameof_udentify_resource_, nameof_udentify_password_,
             default_udentify_user_, default_udentify_resource_, default_udentify_password_,
             udentify_user_, udentify_resource_, udentify_password_,
             begin_udentify_resource_, begin_udentify_password_,
             begin_udentify_message_, endof_udentify_message_, 
             udentify_request_message_, udentify_response_message_, 
             begin_udentify_response_message_, endof_udentify_response_message_; 
}; /// class Maint
typedef Maint<> Main;

} /// namespace Base 
} /// namespace Protocol 
} /// namespace Console 
} /// namespace Application 
} /// namespace uLucidity 

#endif /// ndef ULUCIDITY_APPLICATION_CONSOLE_PROTOCOL_BASE_MAIN_HH
