#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <string>
#include <scope.hpp>
#include <vector>

using namespace std;

class Memory
{
    private:
    vector<Scope> scopes;

    public:
    static bool isNumber(string token);
    bool isVariable(string token);
    bool isArray(string token);
    bool isString(string token);
    int getVariable(string token);
    int getArrayElement(string token, int index);
    char getStringElement(string token, int index);
    void setVariable(string token, int value);
    void setArrayElement(string token, int index, int value);
    void setStringElement(string token, int index, char value);
    void newScope();
    void endScope();
};

#endif
