#include <instructions/sleep.hpp>
#include <chrono>
#include <keszeg3i.hpp>
#include <thread>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Sleep::Sleep(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"sleep"};
    keyPositions = {0};
}

void Instructions::Sleep::execute(vector<string> args)
{
    if (args.size() != 2)
    {
        Keszeg3i::error("Usage: sleep <time>");
    }

    int time = memory.isVariable(args[1]) ? memory.getVariable(args[1]) : stoi(args[1]);
    this_thread::sleep_for(chrono::milliseconds(time));
}
