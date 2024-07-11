#ifndef INSTRUCTIONS_DIV_HPP
#define INSTRUCTIONS_DIV_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Div : public Instruction
    {
        public:
        Div(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
