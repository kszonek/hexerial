#include "config.hpp"
#include "hexerial.hpp"

int main(int argc, char *argv[])
{
    Config cfg(argc, argv);

    Hexerial hexerial;
    hexerial.test();
    return 0;
}
