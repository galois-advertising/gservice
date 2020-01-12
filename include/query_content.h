#pragma once

namespace galois::gservice {
class query_content {
public:
    virtual bool init() = 0;
    virtual bool reset() = 0;
    virtual ~query_content() {};
};
}