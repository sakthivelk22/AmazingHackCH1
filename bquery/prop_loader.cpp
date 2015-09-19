#include "prop_loader.hpp"

namespace _proploader
{

PropLoader::PropLoader(std::string propFile)
{
	std::string line;
	std::ifstream buf ;
    buf.open(propFile.c_str(),std::ios_base::in);
	while (buf.is_open() && !buf.eof())
	{
		getline(buf,line);
		if (line.find('=')!=std::string::npos)
		{
			mp.insert(std::pair<std::string,std::string>(line.substr(0,line.find('=')),line.substr(line.find('=')+1,line.size())));
		}
	}
	buf.close();	
}

PropLoader::~PropLoader(){}

std::string PropLoader::getValue(std::string Key)
{
	return mp[Key];
}

void PropLoader::addProp(std::string Key,std::string Value)
{
	mp[Key]=Value;
}
}