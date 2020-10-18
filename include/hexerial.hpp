#ifndef __HEXERIAL_HPP__
#define __HEXERIAL_HPP__

#include <string>

#include "serialport.hpp"

class Hexerial
{
public:
    Hexerial();

    void run(void);

private:
    SerialPort serial;

    std::string mPortName;
    unsigned int mBaudrate;
    bool mVerbose;
    bool mTimestamp;
};

#endif /* __HEXERIAL_HPP__ */
