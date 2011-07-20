#ifndef _w32_Control_hpp__
#define _w32_Control_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include <w32/gdi/Window.hpp>
#include <w32/gdi/Notification.hpp>
  // Notification is included as a shortcut.

namespace w32 { namespace gdi {

        /*!
         * @brief Child window with a specific purpose.
         */
    typedef Window Control;

} }

#endif /* _w32_Control_hpp__ */