#ifndef INSTRUCTIONS_SUBROUTINE_HPP
#define INSTRUCTIONS_SUBROUTINE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Subroutine : public Instruction
    {
        public:
        Subroutine(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
