#include "CSVLoader.hpp"
#include "IndexLoader.hpp"

namespace _csvloader
{

bool CSVLoader::fileexists(std::string filename)
{
  std::ifstream ifile(filename.c_str(),std::ios_base::in);
  if (ifile.good()) {
        ifile.close();
        return true;
    } else {
        ifile.close();
        return false;
    }   
}

CSVLoader::CSVLoader(std::string fileName)
{
    if(fileexists(fileName))
    {
        std::cout << "File exist" << std::endl;
    }
    else
    {
        std::cout << "File not exists" << std::endl;
        return;
    }
    
    std::ifstream inputfile;
    inputfile.open(fileName.c_str(),std::ios_base::in);
    while(inputfile.is_open() && ! inputfile.eof())
    {
        std::string line;
        getline(inputfile,line);
        if(line.length()<=0)
            continue;
        size_t firstcomma=line.find(',');
        size_t lastcomma=line.find_last_of(',');

        std::string custid,attributeName, attributeValue;
        custid = line.substr(0,firstcomma);
        attributeName = line.substr(firstcomma+1,lastcomma-1-firstcomma);
        attributeValue = line.substr(lastcomma+1,line.size());
        
        int custno;
        std::stringstream ss(custid);
        ss>>custno;
        _indexloader::IndexLoader* i = new _indexloader::IndexLoader(custno);
        delete i;
        
    }
}

CSVLoader::~CSVLoader()
{
}

}

