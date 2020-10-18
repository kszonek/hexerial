#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <algorithm>
#include <string>
#include <vector>

class Config
{
public:
    Config(int &argc, char **argv);
    static const std::string &getCmdOption(const std::string &Option,
                                           const std::string &Default = "");
    static bool cmdOptionExists(const std::string &option);

private:
    static std::vector<std::string> args;
};

#endif /* __CONFIG_HPP__ */
