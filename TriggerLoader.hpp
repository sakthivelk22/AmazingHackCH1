#ifndef __TRIGGERLOADER__
#define __TRIGGERLOADER__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace _triggerloader
{

class TriggerLoader
{
private:
    TriggerLoader(){}
public:
    std::vector<std::string> csvlist;
    TriggerLoader(std::string trigFile);
    ~TriggerLoader();

};

}

#endif // __TRIGGERLOADER__
