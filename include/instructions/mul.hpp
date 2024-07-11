#ifndef INSTRUCTIONS_MUL_HPP
#define INSTRUCTIONS_MUL_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Mul : public Instruction
    {
        public:
        Mul(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
