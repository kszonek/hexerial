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
        std::cout << "Hexserial v" << VERSION << std::endl;
    }
}

void Hexerial::run()
{
    while (true)
    {
        std::cout << "Serial loop" << std::endl;
        break;
    }
}
