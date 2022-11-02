///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
///   File: PluginMain.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_PLUGINMAIN_HPP
#define ULUCIDITY_UI_PLUGINMAIN_HPP

#include "uLucidity/OS/DLibraryMain.hpp"

namespace uLucidity {
namespace UI {

typedef OS::DLibraryMainImplements PluginMainImplements;
typedef OS::DLibraryMain PluginMainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: PluginMain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS PluginMain
: virtual public PluginMainImplements, public PluginMainExtends {
public:
    typedef PluginMainImplements Implements;
    typedef PluginMainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PluginMain() {
    }
    virtual ~PluginMain() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init() {
        STDERR_LOG_DEBUG("return true...");
        return true;
    }
    virtual bool Fini() {
        STDERR_LOG_DEBUG("return true...");
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_PLUGINMAIN_HPP 