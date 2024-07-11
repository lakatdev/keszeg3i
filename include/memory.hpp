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
    Memory();
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
    bool isConstant(string token);
    void newScope();
    void endScope();
    void freeArray(string token);
    void freeString(string token);
    void freeVariable(string token);
    void setString(string token, string value);
    int getArraySize(string token);
    int getStringSize(string token);
    string getString(string token);
};

#endif
