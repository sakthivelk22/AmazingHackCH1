#ifndef __CSVLOADER__
#define __CSVLOADER__

#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.hpp"
#include <vector>
#include <algorithm>

namespace _csvloader
{

class CSVLoader
{
private:

public:
    CSVLoader(std::string fileName);
    ~CSVLoader();

};

}

#endif // __CSVLOADER__
