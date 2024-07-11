#ifndef INSTRUCTIONS_ARRSET_HPP
#define INSTRUCTIONS_ARRSET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Arrset : public Instruction
    {
        public:
        Arrset(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
