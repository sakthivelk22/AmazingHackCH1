#include "utils.hpp"

bool fileexists(std::string filename)
{
  std::ifstream ifile(filename.c_str());
  if (ifile.good()) {
        ifile.close();
        return true;
    } else {
        ifile.close();
        return false;
    }   
}

void createfile(std::string filename)
{
    std::ofstream ofile(filename.c_str());
}

void deletefile(std::string filename)
{
    remove(filename.c_str());
}
void appendfile(std::string filename, int itemNo, std::string attributeName, std::string attributeValue)
{
    std::cout << itemNo << "," << attributeName << "," << attributeValue << "\n";
    std::ofstream ofile;
    int status;
    status=checkentry(filename.c_str(),itemNo,attributeName);
    //std::cout << "status" << status << std::endl;
    if(status > 0){
        //std::cout << "  \n delete th entry";
        deletentry(filename.c_str(),itemNo,attributeName,attributeValue);
    }
    ofile.open(filename.c_str(),std::ios_base::app);
    ofile << itemNo << "," << attributeName << "," << attributeValue << "\n";
    ofile.close();
}

int checkentry(std::string filename, int itemNo, std::string attributeName)
{
    int checkstatus;
    checkstatus=0;
    std::ifstream ifile(filename.c_str());
    while(ifile.is_open() && ! ifile.eof())
    {
        std::string line;
        getline(ifile,line);
        if(line.length()<=0)
            continue;
        
        size_t firstcomma=line.find(',');
        size_t lastcomma=line.find_last_of(',');
                
        std::string custid, attributeNameInfile;
        int itemNoInfile;
        custid = line.substr(0,firstcomma);
        std::stringstream convert(custid);
        convert >> itemNoInfile;
        attributeNameInfile = line.substr(firstcomma+1,lastcomma-1-firstcomma);
        
        if(itemNoInfile == itemNo && attributeName == attributeNameInfile)
        {
            checkstatus=1;
            //std::cout << " values" << itemNo << itemNoInfile << "values" << attributeName << attributeNameInfile << checkstatus;
        }
    }
    return checkstatus;
}


void deletentry(std::string filename, int itemNo, std::string attributeName, std::string attributeValue)
{
    std::ifstream ifile(filename.c_str());
    std::ofstream ofile;
    ofile.open("temp.txt",std::ios_base::app);
    
    while(ifile.is_open() && ! ifile.eof())
    {
        std::string line;
        getline(ifile,line);
        if(line.length()<=0)
            continue;
        
        size_t firstcomma=line.find(',');
        size_t lastcomma=line.find_last_of(',');
                
        std::string custid, attributeNameInfile,attributeValueInfile;
        int itemNoInfile;
        custid = line.substr(0,firstcomma);
        std::stringstream convert(custid);
        convert >> itemNoInfile;
        attributeNameInfile = line.substr(firstcomma+1,lastcomma-1-firstcomma);
        attributeValueInfile = line.substr(lastcomma+1,line.size());
        
        if(itemNoInfile == itemNo && attributeName == attributeNameInfile)
        {
                continue;
        }
        else{
            ofile << itemNoInfile << "," << attributeNameInfile << "," << attributeValueInfile << "\n";
        }
    }
    ifile.close();
    ofile.close();
    
    remove(filename.c_str());
    rename("temp.txt",filename.c_str());
    
}