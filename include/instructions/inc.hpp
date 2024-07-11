#ifndef INSTRUCTIONS_INC_HPP
#define INSTRUCTIONS_INC_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Inc : public Instruction
    {
        public:
        Inc(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
