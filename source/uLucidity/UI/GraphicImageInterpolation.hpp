///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: GraphicImageInterpolation.hpp
///
/// Author: $author$
///   Date: 11/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef ULUCIDITY_UI_GRAPHICIMAGEINTERPOLATION_HPP
#define ULUCIDITY_UI_GRAPHICIMAGEINTERPOLATION_HPP

#include "uLucidity/Base/Base.hpp"

namespace uLucidity {
namespace UI {

typedef int GraphicImageInterpolation;
enum {
    GraphicImageInterpolationNone,
    GraphicImageInterpolationDefault,
    GraphicImageInterpolationFast,
    GraphicImageInterpolationSmooth,
};

} // namespace UI 
} // namespace uLucidity 

#endif // ULUCIDITY_UI_GRAPHICIMAGEINTERPOLATION_HPP
        
