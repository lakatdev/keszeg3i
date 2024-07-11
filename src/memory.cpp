#include <memory.hpp>
#include <keszeg3i.hpp>

bool Memory::isVariable(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isVariable(token))
        {
            return true;
        }
    }
}

bool Memory::isString(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            return true;
        }
    }
}

bool Memory::isArray(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isArray(token))
        {
            return true;
        }
    }
}

int Memory::getVariable(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isVariable(token))
        {
            return scopes[i].getVariable(token);
        }
    }
    return 0;
}

int Memory::getArrayElement(string token, int index)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isArray(token))
        {
            return scopes[i].getArrayElement(token, index);
        }
    }
    return 0;
}

char Memory::getStringElement(string token, int index)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            return scopes[i].getStringElement(token, index);
        }
    }
    return 0;
}

void Memory::setVariable(string token, int value)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isVariable(token))
        {
            scopes[i].setVariable(token, value);
            return;
        }
    }
    scopes[scopes.size() - 1].setVariable(token, value);
}

void Memory::setArrayElement(string token, int index, int value)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isArray(token))
        {
            scopes[i].setArrayElement(token, index, value);
            return;
        }
    }
    scopes[scopes.size() - 1].setArrayElement(token, index, value);
}

void Memory::setStringElement(string token, int index, char value)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            scopes[i].setStringElement(token, index, value);
            return;
        }
    }
    scopes[scopes.size() - 1].setStringElement(token, index, value);
}

bool Memory::isNumber(string token)
{
    for (int i = 0; i < token.size(); i++)
    {
        if ((token[i] < 48 || token[i] > 57) && token[i] != 45)
        {
            return false;
        }
    }
    return true;
}

void Memory::newScope()
{
    scopes.push_back(Scope());
}

void Memory::endScope()
{
    if (scopes.size() > 1)
    {
        scopes.pop_back();
    }
    else
    {
        Keszeg3i::error("Cannot end the global scope", true);
    }
}
