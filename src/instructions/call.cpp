#include <instructions/call.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Call::Call(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"call"};
    keyPositions = {0};
}

void Instructions::Call::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 2)
    {
        Keszeg3i::error("Usage: call <subroutine>");
    }

    controlFlow.pushJump(args[1]);
}
