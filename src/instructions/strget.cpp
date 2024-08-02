#include <instructions/strget.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <runtime.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Strget::Strget(Runtime& runtime): Instruction(runtime)
{
    keys = {"<-", ":"};
    keyPositions = {1, 3};
}

void Instructions::Strget::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 5)
    {
        Keszeg3i::error("Usage: Z <- X : Y");
    }

    int y = runtime.memory.isConstant(args[4]) ? stoi(args[4]): runtime.memory.getVariable(args[4]);
    int val = runtime.memory.getStringElement(args[2], y);
    runtime.memory.setVariable(args[0], val);
}
