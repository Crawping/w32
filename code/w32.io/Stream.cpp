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

/*!
 * @file w32.io/Stream.cpp
 * @author Andre Caron (andre.l.caron@gmail.com)
 */

#include <w32.io/Stream.hpp>
#include <w32/Error.hpp>

namespace w32 { namespace io {

    const Stream::Type Stream::Type::character ()
    {
        return (FILE_TYPE_CHAR);
    }

    const Stream::Type Stream::Type::disk ()
    {
        return (FILE_TYPE_DISK);
    }

    const Stream::Type Stream::Type::remote ()
    {
        return (FILE_TYPE_REMOTE);
    }

    const Stream::Type Stream::Type::ipc ()
    {
        return (FILE_TYPE_PIPE);
    }

    const Stream::Type Stream::Type::unknown ()
    {
        return (FILE_TYPE_UNKNOWN);
    }

    Stream::Type Stream::Type::of ( const Stream& stream )
    {
        const ::DWORD result = ::GetFileType(stream.handle());
        if ( result == FILE_TYPE_UNKNOWN ) {
            const ::DWORD error = ::GetLastError();
            if ( error != ERROR_SUCCESS ) {
                UNCHECKED_WIN32C_ERROR(GetFileType,error);
            }
        }
        return (Stream::Type(result));
    }

    Stream::Type::Type ( Value value )
        : myValue(value)
    {
    }

    Stream::Stream ( const Handle& handle )
        : Object(handle)
    {
    }

    Stream::Size Stream::size () const
    {
        ::LARGE_INTEGER value = { 0 };
        const ::BOOL result = ::GetFileSizeEx(handle(),&value);
        if ( result == 0 ) {
            UNCHECKED_WIN32C_ERROR(GetFileSizeEx,::GetLastError());
        }
        return (Stream::Size(value));
    }

    Stream::Position Stream::position () const
    {
        ::LARGE_INTEGER distance = { 0 };
        ::LARGE_INTEGER value = { 0 };
        const ::BOOL result = ::SetFilePointerEx(
            handle(), distance, &value, FILE_CURRENT
            );
        if ( result == 0 ) {
            UNCHECKED_WIN32C_ERROR(SetFilePointerEx,::GetLastError());
        }
        return (Stream::Position(value));
    }

    void Stream::position ( const Position& value ) const
    {
        const ::BOOL result = ::SetFilePointerEx(
            handle(), value.value(), 0, FILE_CURRENT
            );
        if ( result == 0 ) {
            UNCHECKED_WIN32C_ERROR(SetFilePointerEx,::GetLastError());
        }
    }

} }
