///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: version.cpp
///
/// Author: $author$
///   Date: 12/23/2021
///////////////////////////////////////////////////////////////////////
#include "libjson/lib/libjson/version.hpp"
#include "libjson.h"

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_NAME)
#define LIBJSON_LIB_LIBJSON_VERSION_NAME   "libjson"
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_NAME)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_MAJOR)
#define LIBJSON_LIB_LIBJSON_VERSION_MAJOR   __LIBJSON_MAJOR__
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_MAJOR)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_MINOR)
#define LIBJSON_LIB_LIBJSON_VERSION_MINOR   __LIBJSON_MINOR__
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_MINOR)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_RELEASE)
#define LIBJSON_LIB_LIBJSON_VERSION_RELEASE __LIBJSON_PATCH__
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_RELEASE)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD_DATE)
#define LIBJSON_LIB_LIBJSON_VERSION_BUILD_DATE   12/23/2021
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD_DATE)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD)
#define LIBJSON_LIB_LIBJSON_VERSION_BUILD   LIBJSON_LIB_LIBJSON_VERSION_BUILD_DATE
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD)

#if !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD_CHARS)
#define LIBJSON_LIB_LIBJSON_VERSION_BUILD_CHARS XOS_2CHARS(LIBJSON_LIB_LIBJSON_VERSION_BUILD)
#endif /// !defined(LIBJSON_LIB_LIBJSON_VERSION_BUILD_CHARS)

namespace libjson {
namespace lib {
namespace libjson {

namespace which {
/// class versiont
template <class TExtends = xos::lib::extended::version, class TImplements = typename TExtends::implements>
class exported versiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef versiont derives;

    /// constructor / destructor
    versiont(const versiont& copy): extends(copy) {
    }
    versiont(): extends
    (LIBJSON_LIB_LIBJSON_VERSION_NAME, 
     LIBJSON_LIB_LIBJSON_VERSION_MAJOR, LIBJSON_LIB_LIBJSON_VERSION_MINOR, 
     LIBJSON_LIB_LIBJSON_VERSION_RELEASE, LIBJSON_LIB_LIBJSON_VERSION_BUILD_CHARS) {
    }
    virtual ~versiont() {
    }

    /// ...separator
    virtual const char_t* name_separator() const {
        return "_";
    }
    virtual const char_t* revision_separator() const {
        return name_separator();
    }

}; /// class versiont
typedef versiont<> version;
} /// namespace which

/// class version
const xos::lib::version& version::which() {
    static const libjson::which::version version;
    return version;
}

} /// namespace libjson
} /// namespace lib
} /// namespace libjson
