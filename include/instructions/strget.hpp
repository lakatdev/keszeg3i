#ifndef INSTRUCTIONS_STRGET_HPP
#define INSTRUCTIONS_STRGET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Strget : public Instruction
    {
        public:
        Strget(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
