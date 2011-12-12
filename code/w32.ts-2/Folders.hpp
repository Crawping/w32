#ifndef _w32_ts2_Folders_hpp__
#define _w32_ts2_Folders_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"

namespace w32 { namespace ts {

    class Folder;

        /*!
         * @brief Enumerates all sub-folders of a folder.
         */
    class Folders :
        public com::Wrapper< ::ITaskFolderCollection >
    {
        /* construction. */
    public:
            /*!
             * @brief Gets a collection to the sub-folders of a given folder.
             */
        explicit Folders ( const Folder& folder );

        /* methods. */
    public:
            /*!
             * @brief Obtains the number of folders in the collection.
             *
             * To open one of these folders, use the appropriate \c Folder
             * constructor.
             */
        long count () const;
    };

} }

#endif /* _w32_ts2_Folders_hpp__ */