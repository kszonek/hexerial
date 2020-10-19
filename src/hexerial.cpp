#include "hexerial.hpp"

#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "config.hpp"
#include "version.hpp"

Hexerial::Hexerial()
{
    serial.setPortName(Config::getCmdOption("-p", "/dev/ttyUSB0"));
    serial.setBaudrate(stoi(Config::getCmdOption("-b", "9600")));
    mColumns = stoi(Config::getCmdOption("-c", "8"));
    if (mColumns < 1)
        mColumns = 1;
    mVerbose = Config::cmdOptionExists("-v");
    if (mVerbose)
    {
        std::cout << "HEXERIAL " << VERSION << std::endl;
        std::cout << "Serial port: " << serial.getPortName() << std::endl;
        std::cout << "Baudrate: " << serial.getBaudrate() << std::endl;
        std::cout << "Columns: " << mColumns << std::endl;
    }
    if (serial.connect())
    {
        std::cout << "Serial port connected" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open serial port" << std::endl;
        exit(1);
    }
}

void Hexerial::run()
{
    const unsigned int BUFSIZE = 255;
    uint8_t buf[BUFSIZE];
    int c = 0;
    while (serial.isConnected())
    {
        int size = serial.read(buf, BUFSIZE);
        for (int i = 0; i < size; i++)
        {
            std::cout << " 0x" << std::setfill('0') << std::setw(2)
                      << std::right << std::hex << std::uppercase
                      << static_cast<int>(buf[i]);
            if (++c % mColumns == 0)
                std::cout << std::endl;
        }
    }
}
