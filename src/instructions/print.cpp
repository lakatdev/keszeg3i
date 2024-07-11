#include <instructions/print.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <iostream>

using namespace std;

Instructions::Print::Print(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"print"};
    keyPositions = {0};
}

void Instructions::Print::execute(Line line)
{
    vector<string> args = line.getTokens();
    
    if (args[1] == "$")
    {
        int x = memory.getVariable(args[2]);
        cout << x;
    }
    else if (args[1] == "ascii")
    {
        int x = memory.getVariable(args[2]);
        cout << (char)x;
    }
    else if (args[1] == "string")
    {
        cout << memory.getString(args[2]);
    }
    else if (args[1] == "const")
    {
        cout << line.parseString(2);
    }
    else
    {
        Keszeg3i::error("Invalid mode: " + args[1]);
    }
}
