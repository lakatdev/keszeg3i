#include <instructions/exec.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Exec::Exec(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"exec"};
    keyPositions = {0};
}

void Instructions::Exec::execute(Line line)
{
    vector<string> args = line.getTokens();
    system(line.parseString(1).c_str());
}
