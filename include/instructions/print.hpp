#ifndef INSTRUCTIONS_PRINT_HPP
#define INSTRUCTIONS_PRINT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Print : public Instruction
    {
        public:
        Print(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
