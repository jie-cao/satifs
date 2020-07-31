//
// Created by Jie Cao on 7/31/20.
//

#ifndef SATIFS_MAIN_SERVER_H
#define SATIFS_MAIN_SERVER_H
#include <memory>

class NamenodeServer;

class NamenodeServer : public std::enable_shared_from_this<NamenodeServer> {
public:
    void start();
    void stop();
};


#endif //SATIFS_MAIN_SERVER_H
