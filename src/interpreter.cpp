#include <instruction.hpp>
#include <line.hpp>
#include <vector>
#include <interpreter.hpp>
#include <keszeg3i.hpp>

Interpreter::~Interpreter()
{
    for (int i = 0; i < instructions.size(); i++)
    {
        delete instructions[i];
    }
}

void Interpreter::interpret(Line line, int lineNumber)
{
    if (line.getTokens().size() != 0)
    {
        for (int i = 0; i < instructions.size(); i++)
        {
            if (instructions[i]->matches(line))
            {
                instructions[i]->execute(line.getTokens());
                return;
            }
        }
        Keszeg3i::error("Unknown instruction at line " + to_string(lineNumber + 1) + ": " + line.toString());
    }
}

void Interpreter::addInstruction(Instruction* instruction)
{
    instructions.push_back(instruction);
}

