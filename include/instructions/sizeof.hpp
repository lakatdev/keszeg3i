#ifndef INSTRUCTIONS_SIZEOF_HPP
#define INSTRUCTIONS_SIZEOF_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Sizeof : public Instruction
    {
        public:
        Sizeof(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
