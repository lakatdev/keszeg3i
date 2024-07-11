#ifndef INSTRUCTIONS_RETURN_HPP
#define INSTRUCTIONS_RETURN_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Return : public Instruction
    {
        public:
        Return(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
