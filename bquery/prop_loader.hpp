#ifndef __PROPLOADER_HPP
#define __PROPLOADER_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
namespace _proploader
{

class PropLoader
{
private:
	std::map<std::string,std::string> mp;
public:
	PropLoader(std::string propFile);
	~PropLoader();
	std::string getValue(std::string Key);
	void addProp(std::string,std::string);
};
}

#endif // __PROPLOADER_HPP
