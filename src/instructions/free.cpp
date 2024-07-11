#include <instructions/free.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Free::Free(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
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

    memory.freeVariable(args[1]);
    memory.freeArray(args[1]);
    memory.freeString(args[1]);
}
