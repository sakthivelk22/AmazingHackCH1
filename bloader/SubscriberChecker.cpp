#include "SubscriberChecker.hpp"

namespace _subscriber
{

SubscriberChecker::SubscriberChecker(std::string updateList)
{
    idx = new _proploader::PropLoader("subscriber.config");
    fileList = updateList;
}

SubscriberChecker::~SubscriberChecker()
{
    delete idx;
}

void SubscriberChecker::run()
{
    readSubscription();
}

void SubscriberChecker::readSubscription()
{
    std::vector<std::string> content;
    std::string line;
	std::ifstream buf;
    buf.open(idx->getValue("subscribercond").c_str(),std::ios_base::in);
    if (buf.is_open() && !buf.eof())
        getline(buf,line);
	while (buf.is_open() && !buf.eof())
	{
        if (line == "Subscription:")
        {
            getline(buf,line);
            while (buf.is_open() && !buf.eof())
            {
                getline(buf,line);
                if (line == "Subscription:")
                    break;
                content.push_back(line);
                std::cout<<line;
            }
            notifyItems(content);
            content.erase(content.begin(),content.end());
        }
        else
            getline(buf,line);
    }
}

void SubscriberChecker::notifyItems(std::vector<std::string> content)
{
    std::cout<<"notify";
    std::string line;
    int itemNo;
	std::ifstream buf;
    std::string subscriber;
    buf.open(fileList.c_str(),std::ios_base::in);
    while (buf.is_open() && !buf.eof())
	{
        getline(buf,line);
        std::stringstream convert(line);
        convert >> itemNo;
        std::map<std::string,std::string> itemContent = getContent(itemNo);
        bool isNotify=true;
        for (std::vector<std::string>::iterator it=content.begin();it!=content.end();it++)
        {
            std::string attrib= it->substr(0,it->find(' '));
            std::string cond=  it->substr(it->find(' ')+1,it->find_last_of(' '));
            std::string value= it->substr(it->find_last_of(' '),it->size());
            if (attrib!="notify")
                isNotify=runBoolCheck(itemContent[attrib],cond,value);
            else   
                subscriber=value;
        }
        if (isNotify)
            notify(itemNo,subscriber);

    }    
}

bool SubscriberChecker::runBoolCheck(std::string value1,std::string cond,std::string value2)
{
        if (cond=="=")
            return value1==value2;
        else if (cond=="!=")
            return value1!=value2;
        else if (cond==">=")
            return value1>=value2;
        else if (cond=="<=")
            return value1<=value2;
        else if (cond==">")
            return value1>value2;
        else if (cond=="<")
            return value1<value2;
        else 
            return false;
}

}

