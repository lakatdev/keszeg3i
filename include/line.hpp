#ifndef LINE_HPP
#define LINE_HPP

#include <string>
#include <vector>

using namespace std;

class Line
{
    private:
    vector<string> tokens;

    public:
    Line(string line);
    vector<string> getTokens();
    string toString();
    string parseString(int after = 0);
    static void replaceAll(std::string& str, const std::string& from, const std::string& to);
};

#endif
