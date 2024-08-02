#include <instructions/free.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Free::Free(Runtime& runtime): Instruction(runtime)
{
    keys = {"free"};
    keyPositions = {0};
}

void Instructions::Free::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 2)
    {
        Keszeg3i::error("Usage: free X");
    }

    runtime.memory.freeVariable(args[1]);
    runtime.memory.freeArray(args[1]);
    runtime.memory.freeString(args[1]);
}
