#include <iostream>

#include "config.hpp"
#include "hexerial.hpp"
#include "version.hpp"

void print_help(void)
{
    std::cout << "Hexerial " << VERSION << std::endl;
    std::cout << "Usage: " << std::endl;
    std::cout << "\t-b [value]\t"
              << "set baudrate (default: 9600)" << std::endl;
    std::cout << "\t-h\t\t"
              << "show this help dialog" << std::endl;
    std::cout << "\t-p [value]\t"
              << "set serial port path (default: /dev/ttyUSB0)" << std::endl;
    std::cout << "\t-v\t\t"
              << "verbose mode" << std::endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    Config cfg(argc, argv);

    if (Config::cmdOptionExists("-h"))
        print_help();

    Hexerial hexerial;
    hexerial.run();

    return 0;
}
