#ifndef __MESSENGER__
#define __MESSENGER__
#include <string>
#include <map>
#include <iostream>
void notify(int itemNo,std::string subscriberName);
std::map<std::string,std::string> getContent(int itemNo);
#endif