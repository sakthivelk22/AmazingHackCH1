#include "CSVLoader.hpp"

namespace _csvloader
{

bool CSVLoader::fileexists(std::string filename)
{
  std::ifstream ifile(filename);
  if (ifile.good()) {
        ifile.close();
        return true;
    } else {
        ifile.close();
        return false;
    }   
}

CSVLoader::CSVLoader(string fileName)
{
    if(fileexists(fileName))
    {
        cout << "file exist" << endl;
    }
    else
    {
        cout << "File not exists: closing the application" << endl;
        return;
    }
    
    std::ifstream inputfile;
    inputfile.open("sample.txt",ios_base::in);
    int i = 1;
    while(inputfile.is_open() && ! inputfile.eof())
    {
        std::string line;
        getline(inputfile,line);
        if(line.length()<=0)
            continue;
        size_t firstcomma=line.find(',');
        size_t lastcomma=line.find_last_of(',');
        //cout << "First comma" << " " << firstcomma << endl;
        //cout << "last comma" << " " << lastcomma << endl;
        
        string custid,attributeName, attributeValue;
        custid = line.substr(0,firstcomma);
        attributeName = line.substr(firstcomma+1,lastcomma-1-firstcomma);
        attributeValue = line.substr(lastcomma+1,line.size());
        
        //<<Function calling >>
        cout << "Customer Id: " << custid << endl;
        cout << "attributeName: " << attributeName << endl;
        cout << "attributeValue: " << attributeValue << endl;
        
        //cout << "Line number :" << i << endl;
        i++;
    }

    cout << "testing";
    getchar();
	return 0;
    
    
}


CSVLoader::~CSVLoader()
{
}


}

