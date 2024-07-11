#ifndef INSTRUCTIONS_CAT_HPP
#define INSTRUCTIONS_CAT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Cat : public Instruction
    {
        public:
        Cat(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
