#ifndef __CSVLOADER__
#define __CSVLOADER__

#include <iostream>
#include <fstream>
#include <sstream>

namespace _csvloader
{

class CSVLoader
{
private:
    bool fileexists(std::string filename);
public:
    CSVLoader(std::string fileName);
    ~CSVLoader();

};

}

#endif // __CSVLOADER__
