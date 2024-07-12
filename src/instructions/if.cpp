#include <instructions/if.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::If::If(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"if"};
    keyPositions = {0};
}

void Instructions::If::execute(Line line)
{

    vector<string> args = line.getTokens();
    if (args.size() != 4)
    {
        Keszeg3i::error("Usage: if X operator Y");
    }

    bool evaluate = false;
    int x = memory.isConstant(args[1]) ? stoi(args[1]): memory.getVariable(args[1]);
    int y = memory.isConstant(args[3]) ? stoi(args[3]): memory.getVariable(args[3]);

    if (args[2] == "=")
    {
        evaluate = x == y;
    }
    else if (args[2] == "!=")
    {
        evaluate = x != y;
    }
    else if (args[2] == "<")
    {
        evaluate = x < y;
    }
    else if (args[2] == ">")
    {
        evaluate = x > y;
    }
    else if (args[2] == "<=")
    {
        evaluate = x <= y;
    }
    else if (args[2] == ">=")
    {
        evaluate = x >= y;
    }
    else
    {
        Keszeg3i::error("Invalid operator: " + args[2]);
    }

    if (!evaluate)
    {
        controlFlow.jumpToEnd();
    }
    else 
    {
        controlFlow.pushType(ControlFlow::CurrentScopeType::IF);
    }
}
