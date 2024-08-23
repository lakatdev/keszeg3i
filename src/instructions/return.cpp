#include <instructions/return.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Return::Return(Runtime& runtime): Instruction(runtime)
{
    keys = {"rt)"};
    keyPositions = {0};
}

void Instructions::Return::execute(Line line)
{
    vector<string> args = line.getTokens();
    runtime.controlFlow.popJump();
}
