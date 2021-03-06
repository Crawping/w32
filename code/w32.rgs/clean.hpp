#ifndef _w32_rgs_clean_hpp__
#define _w32_rgs_clean_hpp__

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
#include <w32/string.hpp>
#include <w32.rgs/Key.hpp>

namespace w32 { namespace rgs {

    /*!
     * @ingroup w32-rgs
     * @brief Recursively removes all entries under @a root.
     * @param root Key for which all sub-keys and values will be removed.
     *
     * @note @a root itself is not removed. This function is designed to remove
     *  an entire tree of registry keys when the key itself is "owned" by some
     *  other entity (i.e. remove shell extension registration entries
     *  associated to a particular file type and leave the file association key
     *  itself unharmed).
     */
    void clean ( Key& root );

    /*!
     * @ingroup w32-rgs
     * @brief Recursively removes all entries under @a root\@a path.
     * @param root Key for which all sub-keys and values will be removed.
     * @param path Path to the key under the selected root.
     *
     * @note @a root\@a path itself is not removed. This function is designed
     *  to remove an entire tree of registry keys when the key itself is
     *  "owned" by some other entity (i.e. remove shell extension registration
     *  entries associated to a particular file type and leave the file
     *  association key itself unharmed).
     */
    void clean ( Key& root, const string& path );

} }

#endif /* _w32_rgs_clean_hpp__ */
