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

#include <w32.tp/Work.hpp>
#include <w32/Error.hpp>

namespace {

    void abandon ( ::PTP_WORK object ) {}
    void destroy ( ::PTP_WORK object )
    {
        ::CloseThreadpoolWork(object);
    }

}

namespace w32 { namespace tp {

    ::PTP_WORK Work::setup ( ::PTP_CALLBACK_ENVIRON queue,
                             ::PTP_WORK_CALLBACK callback, void * context )
    {
        const ::PTP_WORK handle  =
            ::CreateThreadpoolWork(callback, context, queue);
        if ( handle == 0 )
        {
            const ::DWORD error = ::GetLastError();
            UNCHECKED_WIN32C_ERROR(CreateThreadpoolTimer, error);
        }
        return (handle);
    }

    Work::Handle Work::claim ( ::PTP_WORK object )
    {
        return (Handle(object, &::destroy));
    }

    Work::Handle Work::proxy ( ::PTP_WORK object )
    {
        return (Handle(object, &::abandon));
    }

    Work::Work ( const Handle& handle )
        : myHandle(handle)
    {
    }

    const Work::Handle& Work::handle () const
    {
        return (myHandle);
    }

    void Work::submit ()
    {
        ::SubmitThreadpoolWork(myHandle);
    }

    void Work::wait ( bool cancel_pending )
    {
        ::WaitForThreadpoolWorkCallbacks(
            myHandle, cancel_pending?TRUE:FALSE);
    }

} }
