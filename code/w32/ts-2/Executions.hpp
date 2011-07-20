#ifndef _w32_ts2_Executions_hpp__
#define _w32_ts2_Executions_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"

namespace w32 { namespace ts {

    class Registration;
    class Service;

        /*!
         * @brief Enumerates currently running tasks.
         */
    class Executions :
        public com::Wrapper< ::IRunningTaskCollection >
    {
        /* construction. */
    public:
        explicit Executions ( Service& service );
        explicit Executions ( Registration& task );

        /* methods. */
    public:
            /*!
             * @brief Obtains the number of tasks in the collection.
             *
             * To open one of these tasks, use the appropriate \c RunningTask
             * constructor.
             */
        long count () const;
    };

} }

#endif /* _w32_ts2_Executions_hpp__ */