#ifndef __CSVLOADER__
#define __CSVLOADER__

#include <iostream>
#include <fstream>

namespace _csvloader
{

class CSVLoader
{
private:
    bool CSVLoader::fileexists(const char *filename);
public:
    CSVLoader(string fileName);
    ~CSVLoader();

};

}

#endif // __CSVLOADER__
