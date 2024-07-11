#include <instructions/strget.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Strget::Strget(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
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

    int y = memory.isConstant(args[4]) ? stoi(args[4]): memory.getVariable(args[4]);
    int val = memory.getStringElement(args[2], y);
    memory.setVariable(args[0], val);
}
