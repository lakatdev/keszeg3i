#include <instructions/save.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Save::Save(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"save"};
    keyPositions = {0};
}

void Instructions::Save::execute(Line line)
{
    vector<string> args = line.getTokens();
    // TODO: Implement
}
