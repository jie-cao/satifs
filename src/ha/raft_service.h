//
// Created by Jie Cao on 7/26/20.
//

#ifndef SATIFS_RAFT_SERVICE_H
#define SATIFS_RAFT_SERVICE_H

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>
#include <echo.pb.h>

namespace satifs {
    class RaftService : public ::google::protobuf::Service {
    protected:
        // This class should be treated as an abstract interface.
        inline RaftService() {};
    public:
        virtual ~RaftService();

        typedef EchoService_Stub Stub;

        static const ::google::protobuf::ServiceDescriptor *descriptor();

        virtual void Echo(::google::protobuf::RpcController *controller,
                          const EchoRequest *request,
                          EchoResponse *response,
                          ::google::protobuf::Closure *done);

        // implements Service ----------------------------------------------

        const ::google::protobuf::ServiceDescriptor *GetDescriptor();

        void CallMethod(const ::google::protobuf::MethodDescriptor *method,
                        ::google::protobuf::RpcController *controller,
                        const ::google::protobuf::Message *request,
                        ::google::protobuf::Message *response,
                        ::google::protobuf::Closure *done);

        const ::google::protobuf::Message &GetRequestPrototype(
                const ::google::protobuf::MethodDescriptor *method) const;

        const ::google::protobuf::Message &GetResponsePrototype(
                const ::google::protobuf::MethodDescriptor *method) const;

    private:
        GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RaftService);
    };
}

#endif //SATIFS_RAFT_SERVICE_H
