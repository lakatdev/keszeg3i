#include <keszeg3i.hpp>
#include <runtime.hpp>
#include <interpreter.hpp>
#include <instruction.hpp>
#include <vector>
#include <iostream>
#include <string>

#include <keszegui/window.hpp>

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

    for (const auto& arg : args)
    {
        if (arg == "-d")
        {
            debugMode = true;
        }
    }

    Interpreter interpreter = Interpreter();
    Memory memory = Memory();
    ControlFlow controlFlow = ControlFlow(interpreter);
    KeszegUI::Window window(controlFlow);
    Runtime runtime = Runtime(controlFlow, memory, window, args[args.size() - 1]);

    interpreter.addInstruction(new Instructions::Add(runtime));
    interpreter.addInstruction(new Instructions::Arrget(runtime));
    interpreter.addInstruction(new Instructions::Arrset(runtime));
    interpreter.addInstruction(new Instructions::Call(runtime));
    interpreter.addInstruction(new Instructions::Cat(runtime));
    interpreter.addInstruction(new Instructions::Dec(runtime));
    interpreter.addInstruction(new Instructions::Div(runtime));
    interpreter.addInstruction(new Instructions::End(runtime));
    interpreter.addInstruction(new Instructions::Exec(runtime));
    interpreter.addInstruction(new Instructions::Free(runtime));
    interpreter.addInstruction(new Instructions::If(runtime));
    interpreter.addInstruction(new Instructions::Inc(runtime));
    interpreter.addInstruction(new Instructions::Input(runtime));
    interpreter.addInstruction(new Instructions::Load(runtime));
    interpreter.addInstruction(new Instructions::Mod(runtime));
    interpreter.addInstruction(new Instructions::Mul(runtime));
    interpreter.addInstruction(new Instructions::Print(runtime));
    interpreter.addInstruction(new Instructions::Random(runtime));
    interpreter.addInstruction(new Instructions::Return(runtime));
    interpreter.addInstruction(new Instructions::Save(runtime));
    interpreter.addInstruction(new Instructions::Scope(runtime));
    interpreter.addInstruction(new Instructions::Set(runtime));
    interpreter.addInstruction(new Instructions::Sizeof(runtime));
    interpreter.addInstruction(new Instructions::Sleep(runtime));
    interpreter.addInstruction(new Instructions::Strget(runtime));
    interpreter.addInstruction(new Instructions::Strset(runtime));
    interpreter.addInstruction(new Instructions::Sub(runtime));
    interpreter.addInstruction(new Instructions::Subroutine(runtime));
    interpreter.addInstruction(new Instructions::While(runtime));

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
