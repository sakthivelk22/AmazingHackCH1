#include <iostream>
#include <conio.h>
#include "prop_loader.hpp"
#include "logger.hpp"
#include "TriggerLoader.hpp"
#include "CSVLoader.hpp"
#include "SubscriberChecker.hpp"
int main(int argc, char **argv)
{
    _logger::Logger* log = _logger::Logger::getInstance("System.out");
	_proploader::PropLoader* ip = new _proploader::PropLoader("bloader.config");
    log->log(_level::INFO,"Loading bloader.config");
    while (true)
    {
        
        _triggerloader::TriggerLoader* trg = new _triggerloader::TriggerLoader(ip->getValue("triggerfile"));
        
        for (std::vector<string>::iterator it = trg->csvlist.begin() ; it != trg->csvlist.end(); ++it)
        {
            _csvloader::CSVLoader* csv = new _csvloader::CSVLoader(*it);
            delete csv;
            /* call subscriber loader */
            _subscriber::SubscriberChecker i("list.txt");
            i.run();
        }
         
        delete trg;
        
        log->log(_level::INFO,"Loading " + ip->getValue("circuitbreaker"));
        
        _proploader::PropLoader* breaker = new _proploader::PropLoader(ip->getValue("circuitbreaker"));
        if (breaker->getValue("break")=="1")
        {
            delete breaker;
            break;
        }
        delete breaker;
    }   
    
    
    getchar();
	return 0;
}
