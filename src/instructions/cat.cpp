#include <instructions/cat.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Cat::Cat(Runtime& runtime): Instruction(runtime)
{
    keys = {"cat"};
    keyPositions = {0};
}

void Instructions::Cat::execute(Line line)
{
    vector<string> args = line.getTokens();
    string str = "";
    if (runtime.memory.isString(args[1]))
    {
        str = runtime.memory.getString(args[1]);
    }
    str += line.parseString(2);
    runtime.memory.setString(args[1], str);
}
