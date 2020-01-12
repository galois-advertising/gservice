#include <vector>
#include "gpendingpool/include/gpendingpool.h"
#include "ghead/include/ghead.h"
#include "log.h"

namespace galois::gservice
{

class gservice
{
public:
    explicit gservice(std::string name)
    {
    }
    virtual ~gservice() {}

    template <class work_type>
    bool register_work(const char *name){

    };
    bool init() {
    }
    bool run() {}
    bool wait() {}
};

template<class pbservice> 
class service_trails : public pbservice {
public:
    service_trails(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
    service_trails(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                     ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
    ~service_trails();
    
    inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }
    
    // implements demo_service ------------------------------------------
    
    void get_length(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::galois::gservice::demo::demo_request* request,
                         ::galois::gservice::demo::demo_response* response,
                         ::google::protobuf::Closure* done);
private:
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
    bool owns_channel_;
    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(service_trails);

};
} // namespace galois::gservice
