#include "serialport.hpp"

#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

SerialPort::SerialPort() : portName("/dev/ttyUSB0"), baudrate(0)
{
}

bool SerialPort::connect()
{
    if (connected)
        disconnect();
    fd = open(portName.c_str(), O_RDONLY);
    if (fd < 0)
    {
        connected = false;
    }
    else
    {
        connected = true;
        configure();
    }
    return connected;
}

void SerialPort::disconnect()
{
    if (connected)
    {
        close(fd);
        connected = false;
    }
}

bool SerialPort::isConnected(void)
{
    return connected;
}

unsigned int SerialPort::read(uint8_t *buf, const unsigned int size)
{
    int ret = ::read(fd, buf, size);
    if (ret < 0)
        fprintf(stderr, "Size: %d\n", ret);
    return ret;
}

void SerialPort::configure(void)
{
    struct termios tty;
    if (tcgetattr(fd, &tty) != 0)
    {
        std::cerr << "tcgetattr error " << errno << ", " << std::strerror(errno)
                  << std::endl;
        disconnect();
        return;
    }

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ECHONL;
    tty.c_lflag &= ~ISIG;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;

    tty.c_cc[VTIME] = 1;
    tty.c_cc[VMIN] = 0;

    cfsetispeed(&tty, baudrateFromInt(baudrate));
    cfsetospeed(&tty, baudrateFromInt(baudrate));

    if (tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        std::cerr << "tcsetattr error " << errno << ", " << std::strerror(errno)
                  << std::endl;
        disconnect();
        return;
    }
}

inline unsigned int SerialPort::baudrateFromInt(int baud)
{
    switch (baud)
    {
    case 0:
        return B0;
    case 50:
        return B50;
    case 75:
        return B75;
    case 110:
        return B110;
    case 134:
        return B134;
    case 150:
        return B150;
    case 200:
        return B200;
    case 300:
        return B300;
    case 600:
        return B600;
    case 1200:
        return B1200;
    case 1800:
        return B1800;
    case 2400:
        return B2400;
    case 4800:
        return B4800;
    case 9600:
        return B9600;
    case 19200:
        return B19200;
    case 38400:
        return B38400;
    case 57600:
        return B57600;
    case 115200:
        return B115200;
    case 230400:
        return B230400;
    case 460800:
        return B460800;
    case 500000:
        return B500000;
    case 576000:
        return B576000;
    case 921600:
        return B921600;
    case 1000000:
        return B1000000;
    case 1152000:
        return B1152000;
    case 1500000:
        return B1500000;
    case 2000000:
        return B2000000;
    case 2500000:
        return B2500000;
    case 3000000:
        return B3000000;
    case 3500000:
        return B3500000;
    case 4000000:
        return B4000000;
    default:
        std::cerr << "Unknown baudrate: " << baud << std::endl;
        exit(1);
    }
}
