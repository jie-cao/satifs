//
// Created by Jie Cao on 7/19/20.
//

#include <string>

#ifndef SATIFS_INODE_ATTRIBUTES_H
#define SATIFS_INODE_ATTRIBUTES_H

namespace satifs {
    class INodeAttributes {
        public:
            virtual bool is_directory() = 0;
            virtual std::vector<uint8_t> get_local_name_bytes() = 0;
            virtual std::string get_user_name() = 0;
            virtual std::string get_group_name() = 0;
            virtual long get_permission_long() = 0;
            virtual long get_modification_time() = 0;
            virtual long get_access_time() = 0;
    };
}


#endif //SATIFS_INODE_ATTRIBUTES_H
