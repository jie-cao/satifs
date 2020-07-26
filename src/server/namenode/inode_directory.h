
#ifndef SATIFS_INODE_DIRECTORY_H
#define SATIFS_INODE_DIRECTORY_H

#include "inode.h"

namespace satifs {
    class INodeDirectory: public INode {
        public:
        virtual bool is_directory();
    };
}


#endif