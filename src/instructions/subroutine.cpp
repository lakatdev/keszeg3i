#include <instructions/subroutine.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <runtime.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Subroutine::Subroutine(Runtime& runtime): Instruction(runtime)
{
    keys = {"(rt"};
    keyPositions = {0};
}

void Instructions::Subroutine::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 2)
    {
        Keszeg3i::error("Invalid declaration, usage: (rt <subroutine>");
    }

    if (runtime.controlFlow.isStackEmpty())
    {
        runtime.controlFlow.jumpToRtEnd(args[1]);
    }
}
