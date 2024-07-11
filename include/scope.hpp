#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Scope
{
    private:
    unordered_map<string, vector<int>> arrays;
    unordered_map<string, int> variables;
    unordered_map<string, string> strings;

    public:
    Scope();
    int getVariable(string token);
    int getArrayElement(string token, int index);
    char getStringElement(string token, int index);
    void setVariable(string token, int value);
    void setArrayElement(string token, int index, int value);
    void setStringElement(string token, int index, char value);
    bool isVariable(string token);
    bool isArray(string token);
    bool isString(string token);
};

#endif
