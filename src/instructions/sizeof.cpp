#include <instructions/sizeof.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Sizeof::Sizeof(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
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

    if (memory.isArray(args[2]))
    {
        memory.setVariable(args[0], memory.getArraySize(args[2]));
    }
    else if (memory.isString(args[2]))
    {
        memory.setVariable(args[0], memory.getStringSize(args[2]));
    }
    else
    {
        Keszeg3i::error(args[2] + " is not an array or a string");
    }
}
