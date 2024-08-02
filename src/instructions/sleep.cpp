#include <instructions/sleep.hpp>
#include <chrono>
#include <keszeg3i.hpp>
#include <thread>
#include <runtime.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Sleep::Sleep(Runtime& runtime): Instruction(runtime)
{
    keys = {"sleep"};
    keyPositions = {0};
}

void Instructions::Sleep::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 2)
    {
        Keszeg3i::error("Usage: sleep X");
    }

    int time = runtime.memory.isConstant(args[1]) ? stoi(args[1]): runtime.memory.getVariable(args[1]);
    this_thread::sleep_for(chrono::milliseconds(time));
}
