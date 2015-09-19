#include "IndexPointer.hpp"

namespace _indexpointer
{

IndexPointer::IndexPointer(int itemNo)
{
    //log = _logger::Logger::getInstance("System.out");
    //log->log(_level::INFO,"Loading config..");
    idx = new _proploader::PropLoader("IndexLoader.config");
    this->itemNo = itemNo;
    
}

IndexPointer::~IndexPointer()
{
    delete idx;
}

bool IndexPointer::loadData()
{
    //log->log(_level::INFO,"Loading data.."+itemNo);
    std::string line;
	std::ifstream buf;
    std::vector<std::string> vecontent;
    bool isfound=false;
    buf.open(idx->getValue("IndexFile").c_str(),std::ios_base::in);
	while (buf.is_open() && !buf.eof())
	{
		getline(buf,line);
        while(line.find(':')!=std::string::npos)
		{
            vecontent.push_back(line.substr(0,line.find(':')));
			line = line.substr(line.find(':')+1,line.size());
		}
        int startnum,endnum;
        std::stringstream convert;
        convert<<vecontent[0]<<" "<<vecontent[1];
        convert >>startnum>>endnum;
        
        if ((itemNo>=startnum)&&(itemNo<=endnum))
        {
            isfound = true;
            break;
        }
        vecontent.erase(vecontent.begin(),vecontent.end());
    }
    buf.close();

    if (isfound != false)
    {
      //  log->log(_level::INFO,"searching datafile...");
        while(fileexists(vecontent[2]+".lock"))
        {
            //log->log(_level::INFO,"lock file already exists: loop till lock file clears");
            Sleep(10);
        }
        buf.open(vecontent[2].c_str(),std::ios_base::in);
        
        std::ifstream inputfile;
        inputfile.open(vecontent[2].c_str(),std::ios_base::in);
        while(inputfile.is_open() && ! inputfile.eof())
        {
            std::string line;
            getline(inputfile,line);
            if(line.length()<=0)
                continue;
            size_t firstcomma=line.find(',');
            std::string custid,attributeName, attributeValue;
            custid = line.substr(0,firstcomma);
            int custno;
            std::stringstream ss(custid);
            ss>>custno;            
            if (itemNo!=custno)
                continue;
            else
            {
                size_t lastcomma=line.find_last_of(',');
                attributeName = line.substr(firstcomma+1,lastcomma-1-firstcomma);
                attributeValue = line.substr(lastcomma+1,line.size());
                content.insert(std::pair<std::string,std::string>(attributeName,attributeValue));
            }
        }
    }
    return content.size()==0?false:true;
}

void IndexPointer::displayContent()
{
    for (std::map<std::string,std::string>::iterator it=content.begin(); it!=content.end(); ++it)
        std::cout << it->first << " = " << it->second << std::endl;
}

}

