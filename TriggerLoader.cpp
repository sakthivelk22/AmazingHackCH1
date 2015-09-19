#include "TriggerLoader.hpp"

namespace _triggerloader
{

TriggerLoader::TriggerLoader(std::string trigFile)
{
   	std::string line;
	std::ifstream buf ;
    buf.open(trigFile.c_str(),std::ios_base::in);
	while (buf.is_open() && !buf.eof())
	{
		getline(buf,line);
        csvlist.push_back(line);
	}
	buf.close();
}

TriggerLoader::~TriggerLoader()
{
}


}

