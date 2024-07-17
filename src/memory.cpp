#include <memory.hpp>
#include <keszeg3i.hpp>

Memory::Memory()
{
    newScope();
}

bool Memory::isVariable(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isVariable(token))
        {
            return true;
        }
    }
    return false;
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
    return false;
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
    return false;
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
    Keszeg3i::error("Variable " + token + " has not been declared");
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
    Keszeg3i::error("Array " + token + " has not been declared");
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
    Keszeg3i::error("String " + token + " has not been declared");
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

bool Memory::isConstant(string token)
{
    return isNumber(token);
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

void Memory::freeArray(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isArray(token))
        {
            scopes[i].freeArray(token);
        }
        break;
    }
}

void Memory::freeString(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            scopes[i].freeString(token);
        }
        break;
    }
}

void Memory::freeVariable(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isVariable(token))
        {
            scopes[i].freeVariable(token);
        }
        break;
    }
}

void Memory::setString(string token, string value)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            scopes[i].setString(token, value);
            return;
        }
    }
    scopes[scopes.size() - 1].setString(token, value);
}

int Memory::getArraySize(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isArray(token))
        {
            return scopes[i].getArraySize(token);
        }
    }
    return 0;
    Keszeg3i::error("Array " + token + " has not been declared");
}

int Memory::getStringSize(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            return scopes[i].getStringSize(token);
        }
    }
    Keszeg3i::error("String " + token + " has not been declared");
    return 0;
}

string Memory::getString(string token)
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        if (scopes[i].isString(token))
        {
            return scopes[i].getString(token);
        }
    }
    Keszeg3i::error("String " + token + " has not been declared");
    return "";
}
