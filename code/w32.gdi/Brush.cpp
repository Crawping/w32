// Copyright (c) 2009-2012, Andre Caron (andre.l.caron@gmail.com)
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <w32.gdi/Brush.hpp>
#include <w32.gdi/Color.hpp>
#include <w32.gdi/SystemColor.hpp>
#include <w32/Error.hpp>
#include <iostream>

namespace {

    ::HBRUSH create ( ::COLORREF color )
    {
        const ::HBRUSH handle = ::CreateSolidBrush(color);
        if ( handle == 0 )
        {
            const ::DWORD error = ::GetLastError();
            UNCHECKED_WIN32C_ERROR(CreateSolidBrush, error);
        }
        return (handle);
    }

    ::HBRUSH fetch_system ( int color )
    {
        const ::HBRUSH handle = ::GetSysColorBrush(color);
        if ( handle == 0 )
        {
            const ::DWORD error = ::GetLastError();
            UNCHECKED_WIN32C_ERROR(GetSysColorBrush, error);
        }
        return (handle);
    }

    ::HBRUSH fetch ( int brush )
    {
        const ::HGDIOBJ handle = ::GetStockObject(brush);
        if ( handle == 0 )
        {
            const ::DWORD error = ::GetLastError();
            UNCHECKED_WIN32C_ERROR(GetStockObject, error);
        }
        return (::HBRUSH(handle));
    }

    void destroy ( ::HBRUSH object )
    {
        if ( ::DeleteObject(object) == FALSE )
        {
            const w32::Error error(::GetLastError());
            std::cerr << "[[[ " << error << " ]]]" << std::endl;
        }
    }

    void abandon ( ::HBRUSH object )
    {
    }

}

namespace w32 { namespace gdi {

    Brush::Handle Brush::claim ( ::HBRUSH object )
    {
        return (Brush::Handle(object, &::destroy));
    }

    Brush::Handle Brush::proxy ( ::HBRUSH object )
    {
        return (Brush::Handle(object, &::abandon));
    }

    const Brush Brush::null ()
    {
        return (Brush(proxy(::fetch(NULL_BRUSH))));
    }

    const Brush Brush::white ()
    {
        return (Brush(proxy(::fetch(WHITE_BRUSH))));
    }

    const Brush Brush::lightGray ()
    {
        return (Brush(proxy(::fetch(LTGRAY_BRUSH))));
    }

    const Brush Brush::gray ()
    {
        return (Brush(proxy(::fetch(GRAY_BRUSH))));
    }

    const Brush Brush::darkGray ()
    {
        return (Brush(proxy(::fetch(DKGRAY_BRUSH))));
    }

    const Brush Brush::black ()
    {
        return (Brush(proxy(::fetch(BLACK_BRUSH))));
    }

    Brush::Brush ( const Handle& handle )
        : myHandle(handle)
    {
    }

    Brush::Brush ( const Color& color )
        : myHandle(claim(::create(color.value())))
    {
    }

    Brush::Brush ( const SystemColor& color )
        : myHandle(proxy(::fetch_system(color)))
    {
    }

    const Brush::Handle& Brush::handle () const
    {
        return (myHandle);
    }

} }
