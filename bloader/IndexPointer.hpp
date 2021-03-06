#ifndef __INDEXPOINTER__
#define __INDEXPOINTER__

#include <string>
#include <map>
#include <vector>
#include "prop_loader.hpp"
//#include "logger.hpp"
#include <sstream>
#include "utils.hpp"
#include <windows.h>
namespace _indexpointer
{

class IndexPointer
{
private:
    
    _proploader::PropLoader* idx;
    int itemNo;
    //_logger::Logger* log;
public:
    std::map<std::string,std::string> content;
    IndexPointer(int itemNo);
    ~IndexPointer();
    bool loadData();
    void displayContent();

};

}

#endif // __INDEXPOINTER__
