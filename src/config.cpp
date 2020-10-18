#include "config.hpp"

#include <iostream>

using namespace std;

Config::Config(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        Config::args.push_back(string(argv[i]));
    }
}

vector<string> Config::args;

const string &Config::getCmdOption(const string &option,
                                   const string &defaultvalue)
{
    vector<string>::const_iterator itr;
    itr = find(Config::args.begin(), Config::args.end(), option);
    if (itr != Config::args.end() && ++itr != Config::args.end())
    {
        return *itr;
    }
    return defaultvalue;
}

bool Config::cmdOptionExists(const string &option)
{
    return find(Config::args.begin(), Config::args.end(), option)
           != Config::args.end();
}
