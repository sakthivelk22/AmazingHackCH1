#include "messenger.hpp"

void notify(int itemNo,std::string subscriberName)
{
   std::cout<<"Notified " <<subscriberName<<std::endl;
   /* To be Implemented*/
}

std::map<std::string,std::string> getContent(int itemNo)
{
    /* to be implemented else where */
    std::map<std::string,std::string> content;
    content.insert(std::pair<std::string,std::string>("publisher","William Morrow"));
    return content;
}