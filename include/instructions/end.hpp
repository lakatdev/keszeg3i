#ifndef INSTRUCTIONS_END_HPP
#define INSTRUCTIONS_END_HPP

#include <instruction.hpp>

namespace Instructions
{
    class End : public Instruction
    {
        public:
        End(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
