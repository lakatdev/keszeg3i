#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <string>
#include <line.hpp>
#include <vector>
#include <interpreter.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

class Runtime
{
    private:
    void readLines(string source);

    public:
    ControlFlow& controlFlow;
    Memory& memory;
    Runtime(ControlFlow& controlFlow, Memory& memory, string source);
    void run();
};

#endif
