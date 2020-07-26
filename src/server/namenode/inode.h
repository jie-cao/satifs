//
// Created by Jie Cao on 7/19/20.
//

#ifndef SATIFS_INODE_H
#define SATIFS_INODE_H
#include "inode_attributes.h"
#include <brpc/server.h>

namespace satifs {
    class INode : public INodeAttributes {
    public:
        INode(){};
        ~INode(){};
        INode* parent;
        virtual long getId() = 0;
    };
}

#endif //SATIFS_INODE_H
