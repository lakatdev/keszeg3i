#include <iostream>
#include <string>
#include <vector>
#include <keszeg3i.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        vector<string> args;
        for (int i = 0; i < argc; i++)
        {
            args.push_back(argv[i]);
        }
        Keszeg3i keszeg3i(args);
    }
    catch (const char* m)
    {
        std::cout << "\033[31m" << m << "\033[0m" << std::endl;
    }
    return 0;
}
