#include <string>
#include "demo.pb.h"
#include "log.h"
using namespace demo;


int main()
{
    log(LOG_LEVEL::DEBUG, "Start,%d", 1);
    demo_response response;
    response.set_name("gservice");
    demo_request request;
    return 0;
}