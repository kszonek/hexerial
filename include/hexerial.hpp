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

    int mColumns;
    bool mVerbose;
};

#endif /* __HEXERIAL_HPP__ */
