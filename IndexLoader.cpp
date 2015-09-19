#include "IndexLoader.hpp"

namespace _indexloader
{

IndexLoader::IndexLoader(int itemNo)
{
    this->itemNo=itemNo;
    indx = new _proploader::PropLoader("IndexLoader.config");
    std::cout<<indx->getValue("IndexFile");
    std::string line;
	std::ifstream buf;
    bool isfound=false;
    buf.open(indx->getValue("IndexFile").c_str(),std::ios_base::in);
	while (buf.is_open() && !buf.eof())
	{
		getline(buf,line);
        while(line.find(':')!=std::string::npos)
		{
            content.push_back(line.substr(0,line.find(':')));
			line = line.substr(line.find(':')+1,line.size());
		}
        int startnum,endnum;
        std::stringstream convert;
        convert<<content[0]<<" "<<content[1];
        convert >>startnum>>endnum;
        
        if ((itemNo>=startnum)&&(itemNo<=endnum))
        {
            isfound = true;
            std::cout<<"found";
            break;
        }
        content.erase(content.begin(),content.end());
    }
    buf.close();
    
    if(isfound==false)
    {
        int startnum,endnum;
        int x= (itemNo/1000);
        
        startnum=((x*1000)+1);
        endnum=((x+1)*1000);
        
        std::cout<<"x is "<<x<<" "<<startnum<<" "<<endnum<<std::endl;
        
        std::stringstream convert;
        std::string startstr,endstr;
        
        convert<<startnum<<" "<<endnum;
        convert>>startstr>>endstr;
        content.push_back(startstr);
        content.push_back(endstr);
        content.push_back(endstr+".data");
        content.push_back(indx->getValue("Path"));
        content.push_back(indx->getValue("Server"));
        std::string line;
        std::ofstream buf;
        
        buf.open(indx->getValue("IndexFile").c_str(),std::ios_base::app);
        for(std::vector<std::string>::iterator it=content.begin();it!=content.end();it++)
        {
            buf<<*it<<":";
        }
        buf<<std::endl;
        
        buf.close();
    }
}

IndexLoader::~IndexLoader()
{
}

void IndexLoader::load()
{
}

}

