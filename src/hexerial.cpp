#include "hexerial.hpp"

#include <iostream>

#include "config.hpp"
#include "version.hpp"

Hexerial::Hexerial()
{
    mPortName = Config::getCmdOption("-p", "/dev/ttyUSB0");
    mBaudrate = stoi(Config::getCmdOption("-b", "9600"));
    mTimestamp = Config::cmdOptionExists("-t");
    mVerbose = Config::cmdOptionExists("-v");
    if (mVerbose)
    {
        std::cout << "HEXERIAL " << VERSION << std::endl;
        std::cout << "Serial port: " << mPortName << std::endl;
        std::cout << "Baudrate: " << mBaudrate << std::endl;
        std::cout << "Timestamp print: " << (mTimestamp ? "yes" : " no")
                  << std::endl;
        std::cout << "Serial port: " << mPortName << std::endl;
    }
}

void Hexerial::run()
{
    if (mVerbose)
        std::cout << "Main loop starting" << std::endl;
    while (true)
    {
        break;
    }
    if (mVerbose)
        std::cout << "Main loop finished" << std::endl;
}
