#ifndef __SERIALPORT_HPP__
#define __SERIALPORT_HPP__

#include <string>

class SerialPort
{
public:
    SerialPort();

private:
    int fd;

    std::string mPortName;
    unsigned int mBaudrate;

public:
    void setPortName(const std ::string &name) { mPortName = name; }
    const std::string &getPortName(void) const { return mPortName; }

    void setBaudrate(const int &baud) { mBaudrate = baud; }
    const int getBaudrate(void) const { return mBaudrate; }
};

#endif /* __SERIALPORT_HPP__ */
