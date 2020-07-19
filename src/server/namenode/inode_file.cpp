#include "inode_file.h"

namespace satifs{
    void INodeFile::add_block(BlockInfo* blockInfo) {
        this->blocks.push_back(blockInfo);
    }

    BlockInfo *INodeFile::get_last_block() {
        return this->blocks.empty()? nullptr : blocks[blocks.size() - 1];
    }

    std::vector<BlockInfo *> INodeFile::get_blocks() {
        return this->blocks;
    }
}