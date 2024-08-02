#include <instructions/mod.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Mod::Mod(Runtime& runtime): Instruction(runtime)
{
    keys = {"=", "%"};
    keyPositions = {1, 3};
}

void Instructions::Mod::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 5)
    {
        Keszeg3i::error("Usage: X = Y % Z");
    }

    int y = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
    int z = runtime.memory.isConstant(args[4]) ? stoi(args[4]): runtime.memory.getVariable(args[4]);
    runtime.memory.setVariable(args[0], y % z);
}
