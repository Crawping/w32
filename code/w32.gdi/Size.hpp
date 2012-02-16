#ifndef _w32_gdi_Size_hpp__
#define _w32_gdi_Size_hpp__

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

#include "__configure__.hpp"

namespace w32 { namespace gdi {

    class Size
    {
        /* nested types. */
    public:
        typedef ::SIZE Data;

        /* data. */
    private:
        Data myData;

        /* construction. */
    public:
        Size ()
        {
            myData.cx = 0, myData.cy = 0;
        }

        Size ( long width, long height )
        {
            myData.cx = width, myData.cy = height;
        }

        Size ( const Data& value )
            : myData(value)
        {}

        /* methods. */
    public:
        Data& data () {
            return (myData);
        }

        const Data& data () const {
            return (myData);
        }

        void width ( long value ) {
            myData.cx = value;
        }

        long width () const {
            return (myData.cx);
        }

        void height ( long value ) {
            myData.cy = value;
        }

        long height () const {
            return (myData.cy);
        }
    };

} }

#endif /* _w32_gdi_Size_hpp__ */
