#include <instructions/set.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <runtime.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Set::Set(Runtime& runtime): Instruction(runtime)
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

    int y = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
    runtime.memory.setVariable(args[0], y);
}
