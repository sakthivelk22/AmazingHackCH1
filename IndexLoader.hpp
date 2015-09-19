#ifndef __INDEXLOADER__
#define __INDEXLOADER__

#include "prop_loader.hpp"
#include "util.h"
#include <vector>
#include <sstream>

namespace _indexloader
{

class IndexLoader
{
private:
    void checknSet(std::string indexFile);
    int itemNo;
    std::vector<std::string> content;
    _proploader::PropLoader* indx;
    void load();
public:
    IndexLoader(int itemNo);
    ~IndexLoader();

};

}

#endif // __INDEXLOADER__
