#include <instructions/random.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <cstdlib>
#include <runtime.hpp>

using namespace std;

Instructions::Random::Random(Runtime& runtime): Instruction(runtime)
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

    int y = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
    runtime.memory.setVariable(args[1], rand() % y);
}
