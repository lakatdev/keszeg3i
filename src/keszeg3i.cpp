#include <keszeg3i.hpp>
#include <runtime.hpp>
#include <interpreter.hpp>
#include <instruction.hpp>
#include <vector>
#include <iostream>
#include <string>

#include <instructions/add.hpp>
#include <instructions/arrget.hpp>
#include <instructions/arrset.hpp>
#include <instructions/call.hpp>
#include <instructions/cat.hpp>
#include <instructions/dec.hpp>
#include <instructions/div.hpp>
#include <instructions/end.hpp>
#include <instructions/exec.hpp>
#include <instructions/free.hpp>
#include <instructions/if.hpp>
#include <instructions/inc.hpp>
#include <instructions/input.hpp>
#include <instructions/load.hpp>
#include <instructions/mod.hpp>
#include <instructions/mul.hpp>
#include <instructions/print.hpp>
#include <instructions/random.hpp>
#include <instructions/return.hpp>
#include <instructions/save.hpp>
#include <instructions/set.hpp>
#include <instructions/scope.hpp>
#include <instructions/sizeof.hpp>
#include <instructions/sleep.hpp>
#include <instructions/strget.hpp>
#include <instructions/strset.hpp>
#include <instructions/sub.hpp>
#include <instructions/subroutine.hpp>
#include <instructions/while.hpp>

using namespace std;

bool Keszeg3i::debugMode = false;

Keszeg3i::Keszeg3i(vector<string> args)
{
    if (args.size() != 2 && args.size() != 3)
    {
        error("Usage: keszeg3i (<flags>) <file>", true);
    }

    for (const auto& arg : args) {
        if (arg == "-d") {
            debugMode = true;
        }
    }

    Interpreter interpreter = Interpreter();
    Memory memory = Memory();
    ControlFlow controlFlow = ControlFlow(interpreter);
    Runtime runtime = Runtime(controlFlow, memory, args[args.size() - 1]);

    interpreter.addInstruction(new Instructions::Add(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Arrget(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Arrset(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Call(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Cat(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Dec(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Div(controlFlow, memory));
    interpreter.addInstruction(new Instructions::End(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Exec(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Free(controlFlow, memory));
    interpreter.addInstruction(new Instructions::If(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Inc(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Input(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Load(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Mod(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Mul(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Print(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Random(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Return(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Save(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Scope(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Set(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Sizeof(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Sleep(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Strget(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Strset(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Sub(controlFlow, memory));
    interpreter.addInstruction(new Instructions::Subroutine(controlFlow, memory));
    interpreter.addInstruction(new Instructions::While(controlFlow, memory));

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

void Keszeg3i::debug(string message)
{
    if (debugMode)
    {
        std::cout << "\033[33m" << message << "\033[0m" << std::endl;
    }
}
