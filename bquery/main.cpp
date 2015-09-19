#include <iostream>
#include <sstream>
#include "logger.hpp"
#include "IndexPointer.hpp"
#include <conio.h>

int main(int argc, char **argv)
{
    _logger::Logger* log = _logger::Logger::getInstance("System.out");
    
    log->log(_level::INFO,"Starting bquery server...");
    bool cont = true;
    while(cont)
    {
        int itemNo;
        std::string item;
        std::cout<<"Enter the ItemNo:"<<std::endl;
        std::cin>>item;
        std::stringstream convert(item);
        convert >> itemNo;
        
        _indexpointer::IndexPointer ip(itemNo);
        if (ip.loadData())
            ip.displayContent();
        else
            std::cout << "No Value to display"<<std::endl;
        
        std::cout << "Do you want to Continue (Y/N) :"<<std::endl;
        std::cin >> item;
        if ( (item=="N") || (item=="n"))
            cont = false;
            
    }
	
    getchar();
	return 0;
}
