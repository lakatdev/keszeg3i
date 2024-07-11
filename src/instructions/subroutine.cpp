#include <instructions/subroutine.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Subroutine::Subroutine(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
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
}
