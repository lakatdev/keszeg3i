#ifndef INSTRUCTIONS_STRSET_HPP
#define INSTRUCTIONS_STRSET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Strset : public Instruction
    {
        public:
        Strset(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
