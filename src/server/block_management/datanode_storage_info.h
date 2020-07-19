//
// Created by Jie Cao on 7/19/20.
//

#ifndef SATIFS_DATANODE_STORAGE_INFO_H
#define SATIFS_DATANODE_STORAGE_INFO_H

#include "server/block_management/block_info.h"

class DatanodeStorageInfo {
public:
    BlockInfo* blockList;
};


#endif //SATIFS_DATANODE_STORAGE_INFO_H
