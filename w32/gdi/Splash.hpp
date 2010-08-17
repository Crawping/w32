#ifndef _w32_gdi_Splash_hpp__
#define _w32_gdi_Splash_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include <w32/NotCopyable.hpp>
#include <w32/gdi/DeviceIndependantBitmap.hpp>
#include <w32/mt/Thread.hpp>

namespace w32 { namespace gdi {

    class W32_GDI_EXPORT Splash :
        private NotCopyable
    {
        /* data. */
    private:
        FileBitmap myBackground;
        mt::Thread myThread;

        /* construction. */
    public:
        explicit Splash ( const string& path );
        ~Splash ();
    };

} }

#endif /* _w32_gdi_Splash_hpp__ */
