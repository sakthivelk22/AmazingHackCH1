#include <iostream>
#include <conio.h>
#include "prop_loader.hpp"
#include "logger.hpp"

int main(int argc, char **argv)
{
    _logger::Logger* log = _logger::Logger::getInstance("System.out");
	_proploader::PropLoader* ip = new _proploader::PropLoader("bloader.config");
    log->log(_level::INFO,"Loading bloader.config");
    std::cout<<ip->getValue("inputfolderpath");
    std::cout<<ip->getValue("circuitbreaker");
    while (true)
    {
        log->log(_level::INFO,"Loading " + ip->getValue("circuitbreaker"));
        _proploader::PropLoader* breaker = new _proploader::PropLoader(ip->getValue("circuitbreaker"));
        if (breaker->getValue("break")=="1")
            break;
        
        /* TO DO actual work*/
    }
    getchar();
	return 0;
}
