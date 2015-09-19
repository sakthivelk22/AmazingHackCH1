#include "CSVLoader.hpp"
#include "IndexLoader.hpp"

namespace _csvloader
{

CSVLoader::CSVLoader(std::string fileName)
{
    if(fileexists(fileName))
    {
        std::cout << " Input File exist" << std::endl;
    }
    else
    {
        std::cout << "File not exists" << std::endl;
        return;
    }
    
    std::ifstream inputfile;
    std::vector<std::string> itemNoVector;
    int counter=0;
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
        
        if(std::find(itemNoVector.begin(),itemNoVector.end(),custid)==itemNoVector.end()){
            itemNoVector.push_back(custid);  
        }
        
        int custno;
        std::stringstream ss(custid);
        ss>>custno;
        _indexloader::IndexLoader* i = new _indexloader::IndexLoader(custno);
        //std::cout<<"fileName;
        i->fileload(attributeName,attributeValue);
        delete i;
    }
    std::ofstream ofile("list.txt",std::ios_base::out);   
    while(!itemNoVector.empty()){
        //std::cout << itemNoVector[counter] << ":::Vector Values" << std::endl;
        ofile << itemNoVector[counter] << "\n";
        itemNoVector.pop_back();
        counter++;
    }
    ofile.close();
}

CSVLoader::~CSVLoader()
{
}

}

