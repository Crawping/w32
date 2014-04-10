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
 * @file w32.io/Folder.cpp
 * @author Andre Caron (andre.l.caron@gmail.com)
 */

#include <w32.io/Folder.hpp>
#include <w32/Error.hpp>

namespace {

    ::HANDLE open ( ::LPCWSTR path, ::DWORD sharing, ::DWORD mode )
    {
        const ::DWORD flags = FILE_FLAG_BACKUP_SEMANTICS;
        const ::HANDLE handle = ::CreateFileW(
            path, 0, sharing, 0, mode, flags, 0
            );
        if ( handle == INVALID_HANDLE_VALUE ) {
            UNCHECKED_WIN32C_ERROR(CreateFile,::GetLastError());
        }
        return (handle);
    }

}

namespace w32 { namespace io {

    Folder::Folder ( const string& path )
        : Object(claim(::open(path.c_str(), FILE_SHARE_READ, OPEN_EXISTING)))
    {
    }

} }