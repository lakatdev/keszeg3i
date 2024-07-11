#include <string>
#include <vector>
#include <line.hpp>
#include <regex>
#include <sstream>

using namespace std;

Line::Line(string line)
{
    line = regex_replace(line, regex("#.*$"), "");
    line = regex_replace(line, regex("\\s{2,}"), " ");
    line = regex_replace(line, regex("\\s+$"), "");

    stringstream ss(line);
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
}

vector<string> Line::getTokens()
{
    return tokens;
}

string Line::toString()
{
    string result = "";
    for (int i = 0; i < tokens.size(); i++)
    {
        result += tokens[i] + " ";
    }
    return result;
}
