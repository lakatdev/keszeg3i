#ifndef INSTRUCTIONS_IF_HPP
#define INSTRUCTIONS_IF_HPP

#include <instruction.hpp>

namespace Instructions
{
    class If : public Instruction
    {
        public:
        If(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
