#include <vector>
#include <scope.hpp>

using namespace std;

int Scope::getVariable(string token)
{
    if (variables.find(token) == variables.end()) {
        variables[token] = 0;
    }
    return variables[token];
}

int Scope::getArrayElement(string token, int index)
{
    if (arrays.find(token) == arrays.end()) {
        arrays[token] = vector<int>(index + 1, 0);
    }
    else if (index >= arrays[token].size()) {
        arrays[token].resize(index + 1, 0);
    }
    return arrays[token][index];
}

char Scope::getStringElement(string token, int index)
{
    if (strings.find(token) == strings.end()) {
        strings[token] = string(index + 1, 0);
    }
    else if (index >= strings[token].size()) {
        strings[token].resize(index + 1, 0);
    }
    return strings[token][index];
}

void Scope::setVariable(string token, int value)
{
    variables[token] = value;
}

void Scope::setArrayElement(string token, int index, int value)
{
    if (arrays.find(token) == arrays.end()) {
        arrays[token] = vector<int>(index + 1, 0);
    }
    else if (index >= arrays[token].size()) {
        arrays[token].resize(index + 1, 0);
    }
    arrays[token][index] = value;
}

void Scope::setStringElement(string token, int index, char value)
{
    if (strings.find(token) == strings.end()) {
        strings[token] = string(index + 1, 0);
    }
    else if (index >= strings[token].size()) {
        strings[token].resize(index + 1, 0);
    }
    strings[token][index] = value;
}

bool Scope::isVariable(string token)
{
    return variables.find(token) != variables.end();
}

bool Scope::isArray(string token)
{
    return arrays.find(token) != arrays.end();
}

bool Scope::isString(string token)
{
    return strings.find(token) != strings.end();
}

void Scope::freeArray(string token)
{
    arrays.erase(token);
}

void Scope::freeString(string token)
{
    strings.erase(token);
}

void Scope::freeVariable(string token)
{
    variables.erase(token);
}

void Scope::setString(string token, string value)
{
    strings[token] = value;
}

int Scope::getArraySize(string token)
{
    return arrays[token].size();
}

int Scope::getStringSize(string token)
{
    return strings[token].size();
}

string Scope::getString(string token)
{
    return strings[token];
}
