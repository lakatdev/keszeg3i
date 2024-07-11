#include <instructions/dec.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Dec::Dec(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"-="};
    keyPositions = {1};
}

void Instructions::Dec::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3 || args.size() != 2)
    {
        Keszeg3i::error("Usage: X -= (Y)");
    }

    int y = 1;
    if (args.size() == 3)
    {
        y = memory.isConstant(args[2]) ? stoi(args[2]): memory.getVariable(args[2]);
    }
    int x = memory.getVariable(args[0]);
    memory.setVariable(args[0], x - y);
}
