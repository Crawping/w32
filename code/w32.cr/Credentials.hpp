#ifndef _w32_cr_Credentials_hpp__
#define _w32_cr_Credentials_hpp__

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
 * @file w32.cr/Credentials.hpp
 * @brief Credentials object, identifies a peer during negotiation.
 */

#include "__configure__.hpp"
#include <w32/types.hpp>
#include <w32/NotCopyable.hpp>

namespace w32 { namespace cr {

    class Certificate;
    class Store;

    //! @addtogroup w32-cr
    //! @{

    /*!
     * @brief Identifies a peer during negotiation.
     */
     class Credentials :
        private NotCopyable
    {
        /* nested types. */
    public:
        typedef ::SCHANNEL_CRED Data;
        typedef ::CredHandle Handle;

        /* data. */
    private:
        Data myData;
        Handle myHandle;

        /* construction. */
    public:
        Credentials ( const Store& store, const Certificate& certificate );
        ~Credentials ();

        /* methods. */
    public:
        /*!
         * @brief Access the native credentials object handle.
         */
        ::PCredHandle handle () const;
    };

    //! @}

} }

#endif /* _w32_cr_Credentials_hpp__ */
