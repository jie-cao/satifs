#include "inode_directory.h"

namespace satifs {
    bool INodeDirectory::is_directory() {
        return true;
    }
}