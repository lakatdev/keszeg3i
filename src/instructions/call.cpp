#include <instructions/call.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Call::Call(Runtime& runtime): Instruction(runtime)
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

    if (!runtime.controlFlow.pushJump(args[1]))
    {
        Keszeg3i::error("Subroutine " + args[1] + " not found");
    }
}
