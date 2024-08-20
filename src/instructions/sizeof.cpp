#include <instructions/sizeof.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Sizeof::Sizeof(Runtime& runtime): Instruction(runtime)
{
    keys = {"sizeof"};
    keyPositions = {1};
}

void Instructions::Sizeof::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: X sizeof Y");
    }

    if (runtime.memory.isArray(args[2]))
    {
        runtime.memory.setVariable(args[0], runtime.memory.getArraySize(args[2]));
    }
    else if (runtime.memory.isString(args[2]))
    {
        runtime.memory.setVariable(args[0], runtime.memory.getStringSize(args[2]));
    }
    else
    {
        runtime.memory.setVariable(args[0], 0);
    }
}
