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

string Line::parseString(int after)
{
    string result = "";
    for (int i = after; i < tokens.size(); i++)
    {
        result += tokens[i];
        if (i < tokens.size() - 1)
        {
            result += " ";
        }
    }
    replaceAll(result, "\\n", "\n");
    replaceAll(result, "\\h", "#");
    replaceAll(result, "\\s", " ");
    replaceAll(result, "\\N", "\n");
    replaceAll(result, "\\H", "#");
    replaceAll(result, "\\S", " ");
    return result;
}

void Line::replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
