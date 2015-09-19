#ifndef __INDEXLOADER__
#define __INDEXLOADER__

#include "prop_loader.hpp"
#include <vector>
#include <sstream>
#include "utils.hpp"
#include <conio.h>
#include <windows.h>

namespace _indexloader
{

class IndexLoader
{
private:
    void checknSet(std::string indexFile);
    int itemNo;
    std::vector<std::string> content;
    _proploader::PropLoader* indx;
public:
    IndexLoader(int itemNo);
    ~IndexLoader();
    void fileload(std::string,std::string);

};

}

#endif // __INDEXLOADER__
