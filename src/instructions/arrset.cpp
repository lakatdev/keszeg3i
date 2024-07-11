#include <instructions/arrset.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Arrset::Arrset(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {":", "<="};
    keyPositions = {1, 3};
}

void Instructions::Arrset::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 5)
    {
        Keszeg3i::error("Usage: X : Y <= Z");
    }

    int y = memory.isConstant(args[2]) ? stoi(args[2]): memory.getVariable(args[2]);
    int z = memory.isConstant(args[4]) ? stoi(args[4]): memory.getVariable(args[4]);
    memory.setArrayElement(args[0], y, z);
}
