#ifndef INSTRUCTIONS_ARRGET_HPP
#define INSTRUCTIONS_ARRGET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Arrget : public Instruction
    {
        public:
        Arrget(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
