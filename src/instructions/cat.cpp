#include <instructions/cat.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Cat::Cat(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"cat"};
    keyPositions = {0};
}

void Instructions::Cat::execute(Line line)
{
    vector<string> args = line.getTokens();
    
    string str = memory.getString(args[1]);
    str += line.parseString(2);
    memory.setString(args[1], str);
}
