#include <vector>
#include "gpendingpool/include/gpendingpool.h"
#include "ghead/include/ghead.h"


namespace galois::gservice
{
work_thread


template < template <class> query_content, 
    template <class> thread_content, 
    class process_content >
class gservice
{
    typedef typename thread_content<query_content> tcontent;
    typedef typename query_content<process_content, thread_content> qcontent; 
public:
    explicit gservice(std::string name)
    {

    }
    virtual ~gservice(){}
    template <class work_type>
    bool register_work(const char * name){

    };
    bool init(){}
    bool run(){}
    bool wait(){}
}
}



