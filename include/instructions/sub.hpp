#ifndef INSTRUCTIONS_SUB_HPP
#define INSTRUCTIONS_SUB_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Sub : public Instruction
    {
        public:
        Sub(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
