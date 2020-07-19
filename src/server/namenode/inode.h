//
// Created by Jie Cao on 7/19/20.
//

#ifndef SATIFS_INODE_H
#define SATIFS_INODE_H
#include "inode_attributes.h"

namespace satifs {
    class INode : INodeAttributes {
    public:
        INode* parent;
        virtual long getId() = 0;
    };
}

#endif //SATIFS_INODE_H
