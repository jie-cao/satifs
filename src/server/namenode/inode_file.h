#ifndef SATIFS_INODE_FILE_H
#define SATIFS_INODE_FILE_H

#include <vector>
#include "inode.h"
#include "server/block_management/block_info.h"

namespace satifs {
    class INodeFile {
    public:
        void add_block(BlockInfo* blockInfo);
        std::vector<BlockInfo*> get_blocks();
        BlockInfo* get_last_block();
    private:
        long header = 0L;
        std::vector<BlockInfo*> blocks;
    };
}

#endif