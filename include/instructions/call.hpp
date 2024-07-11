#ifndef INSTRUCTIONS_CALL_HPP
#define INSTRUCTIONS_CALL_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Call : public Instruction
    {
        public:
        Call(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
