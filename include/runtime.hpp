#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <string>
#include <line.hpp>
#include <vector>
#include <interpreter.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <keszegui/window.hpp>

class Runtime
{
    private:
    void readLines(string source);

    public:
    ControlFlow& controlFlow;
    Memory& memory;
    KeszegUI::Window& window;
    Runtime(ControlFlow& controlFlow, Memory& memory, KeszegUI::Window& window, string source);
    void run();
};

#endif
