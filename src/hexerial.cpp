#include "hexerial.hpp"

#include <iostream>

#include "config.hpp"
#include "version.hpp"

Hexerial::Hexerial()
{
    serial.setPortName(Config::getCmdOption("-p", "/dev/ttyUSB0"));
    serial.setBaudrate(stoi(Config::getCmdOption("-b", "9600")));
    mTimestamp = Config::cmdOptionExists("-t");
    if (CFG_VERBOSE)
    {
        std::cout << "HEXERIAL " << VERSION << std::endl;
        std::cout << "Serial port: " << serial.getPortName() << std::endl;
        std::cout << "Baudrate: " << serial.getBaudrate() << std::endl;
        std::cout << "Timestamp print: " << (mTimestamp ? "yes" : " no")
                  << std::endl;
    }
}

void Hexerial::run()
{
    if (CFG_VERBOSE)
        std::cout << "Main loop starting" << std::endl;
    while (true)
    {
        break;
    }
    if (CFG_VERBOSE)
        std::cout << "Main loop finished" << std::endl;
}
