#include <instructions/set.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Set::Set(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"="};
    keyPositions = {1};
    length = 3;
}

void Instructions::Set::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: X = Y");
    }

    int y = memory.isConstant(args[2]) ? stoi(args[2]): memory.getVariable(args[2]);
    memory.setVariable(args[0], y);
}
