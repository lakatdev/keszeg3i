#ifndef KESZEG3I_HPP
#define KESZEG3I_HPP

#include <vector>
#include <string>

using namespace std;

class Keszeg3i
{
    public:
    Keszeg3i(vector<string> args);
    static void error(string message, bool terminate = false);
    static void debug(string message);
};

#endif
