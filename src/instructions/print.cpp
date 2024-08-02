#include <instructions/print.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <iostream>
#include <runtime.hpp>

using namespace std;

Instructions::Print::Print(Runtime& runtime): Instruction(runtime)
{
    keys = {"print"};
    keyPositions = {0};
}

void Instructions::Print::execute(Line line)
{
    vector<string> args = line.getTokens();
    
    if (args[1] == "$")
    {
        int x = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
        cout << x;
    }
    else if (args[1] == "ascii")
    {
        int x = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
        std::cout << static_cast<char>(x);
    }
    else if (args[1] == "string")
    {
        cout << runtime.memory.getString(args[2]);
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
