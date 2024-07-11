#include <keszeg3i.hpp>
#include <runtime.hpp>
#include <interpreter.hpp>
#include <instruction.hpp>
#include <vector>
#include <iostream>
#include <string>

#include <instructions/sleep.hpp>

using namespace std;

Keszeg3i::Keszeg3i(vector<string> args)
{
    if (args.size() != 2)
    {
        error("Usage: keszeg3i <file>", true);
    }

    Interpreter interpreter = Interpreter();
    Memory memory = Memory();
    ControlFlow controlFlow = ControlFlow(interpreter);
    Runtime runtime = Runtime(controlFlow, memory, args[1]);

    interpreter.addInstruction(new Instructions::Sleep(controlFlow, memory));

    runtime.run();
}

void Keszeg3i::error(string message, bool terminate)
{
    if (terminate)
    {
        throw message;
        return;
    }
    std::cout << "\033[31m" << message << "\033[0m" << std::endl;
}
