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
    int getVariable(string token);
    int getArrayElement(string token, int index);
    char getStringElement(string token, int index);
    void setVariable(string token, int value);
    void setArrayElement(string token, int index, int value);
    void setStringElement(string token, int index, char value);
    void setString(string token, string value);
    string getString(string token);
    bool isVariable(string token);
    bool isArray(string token);
    bool isString(string token);
    void freeArray(string token);
    void freeString(string token);
    void freeVariable(string token);
    int getArraySize(string token);
    int getStringSize(string token);
    void declareArray(string token);
    void declareString(string token);
};

#endif
