#ifndef __HEXERIAL_HPP__
#define __HEXERIAL_HPP__

#include <string>

class Hexerial
{
public:
    Hexerial();

    void run(void);

private:
    std::string mPortName;
    unsigned int mBaudrate;
    bool mVerbose;
    bool mTimestamp;
};

#endif /* __HEXERIAL_HPP__ */
