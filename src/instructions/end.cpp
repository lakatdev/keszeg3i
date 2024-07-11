#include <instructions/add.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Add::Add(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"=", "+"};
    keyPositions = {1, 3};
}

void Instructions::Add::execute(vector<string> args)
{
    
}
