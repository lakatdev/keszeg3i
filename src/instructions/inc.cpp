#include <instructions/inc.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Inc::Inc(Runtime& runtime): Instruction(runtime)
{
    keys = {"+="};
    keyPositions = {1};
}

void Instructions::Inc::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3 && args.size() != 2)
    {
        Keszeg3i::error("Usage: X += (Y)");
    }

    int y = 1;
    if (args.size() == 3)
    {
        y = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
    }
    int x = runtime.memory.getVariable(args[0]);
    runtime.memory.setVariable(args[0], x + y);
}
