#include <instructions/return.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Return::Return(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"return)"};
    keyPositions = {0};
}

void Instructions::Return::execute(Line line)
{
    vector<string> args = line.getTokens();
    controlFlow.popJump();
}
