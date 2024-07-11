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
    ControlFlow& controlFlow;
    Memory& memory;
    void readLines(string source);

    public:
    Runtime(ControlFlow& controlFlow, Memory& memory, string source);
    void run();
};

#endif
