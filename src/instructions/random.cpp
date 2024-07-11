#include <instructions/random.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Random::Random(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"random"};
    keyPositions = {0};
}

void Instructions::Random::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: random X Y");
    }

    int y = memory.isConstant(args[2]) ? stoi(args[2]): memory.getVariable(args[2]);
    memory.setVariable(args[0], rand() % y);
}
