#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <instruction.hpp>
#include <line.hpp>
#include <vector>

class Interpreter
{
    private:
    vector<Instruction*> instructions;

    public:
    ~Interpreter();
    void interpret(Line line, int lineNumber);
    void addInstruction(Instruction* instruction);
};

#endif
