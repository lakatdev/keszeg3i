#ifndef INSTRUCTIONS_INPUT_HPP
#define INSTRUCTIONS_INPUT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Input : public Instruction
    {
        public:
        Input(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
