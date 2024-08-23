#include <instructions/declare.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Declare::Declare(Runtime& runtime): Instruction(runtime)
{
    keys = {"@"};
    keyPositions = {1};
    length = 3;
}

void Instructions::Declare::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: (string / array / var) @ X");
    }

    runtime.memory.freeVariable(args[2]);
    runtime.memory.freeArray(args[2]);
    runtime.memory.freeString(args[2]);

    if (args[0] == "var")
    {
        runtime.memory.setVariable(args[2], 0);
    }
    else if (args[0] == "array")
    {
        runtime.memory.declareArray(args[2]);
    }
    else if (args[0] == "string")
    {
        runtime.memory.declareString(args[2]);
    }
    else
    {
        Keszeg3i::error("Usage: (string / array / var) @ X");
    }
}
