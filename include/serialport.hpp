#ifndef __SERIALPORT_HPP__
#define __SERIALPORT_HPP__

#include <string>

class SerialPort
{
public:
    SerialPort();

    bool connect(void);
    void disconnect(void);
    bool isConnected(void);

    unsigned int read(uint8_t *buf, const unsigned int size);

private:
    int fd;
    bool connected;

    std::string portName;
    unsigned int baudrate;

    void configure(void);

public:
    void setPortName(const std ::string &name) { portName = name; }
    const std::string &getPortName(void) const { return portName; }

    void setBaudrate(const int &baud) { baudrate = baud; }
    const int getBaudrate(void) const { return baudrate; }

    unsigned int baudrateFromInt(int baud);
};

#endif /* __SERIALPORT_HPP__ */
