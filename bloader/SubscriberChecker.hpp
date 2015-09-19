#ifndef __SUBSCRIBERCHECKER__
#define __SUBSCRIBERCHECKER__

#include "prop_loader.hpp"
#include "IndexPointer.hpp"
#include <vector>
#include <sstream>
#include "messenger.hpp"

namespace _subscriber
{

class SubscriberChecker
{
private:
    _proploader::PropLoader* idx;
    std::string fileList;
    void readSubscription();
    void notifyItems(std::vector<std::string> content);
    bool runBoolCheck(std::string,std::string,std::string);
public:
    SubscriberChecker(std::string updateList);
    ~SubscriberChecker();
    void run();
};

}

#endif // __SUBSCRIBERCHECKER__
