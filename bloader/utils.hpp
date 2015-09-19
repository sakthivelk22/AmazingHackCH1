#ifndef __UTIL__
#define __UTIL__

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

bool fileexists(std::string filename);
void createfile(std::string filename);
void appendfile(std::string filename, int itemNo, std::string attributeName, std::string attributeValue);
int checkentry(std::string filename, int itemNo, std::string attributeName);
void deletentry(std::string filename, int itemNo, std::string attributeName, std::string attributeValue);
void deletefile(std::string filename);

#endif // __UTIL__
