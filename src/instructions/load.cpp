#include <instructions/load.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Load::Load(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"load"};
    keyPositions = {0};
}

void Instructions::Load::execute(Line line)
{
    vector<string> args = line.getTokens();
    // TODO: Implement
}
