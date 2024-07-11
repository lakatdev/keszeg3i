#ifndef INSTRUCTIONS_SET_HPP
#define INSTRUCTIONS_SET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Set : public Instruction
    {
        public:
        Set(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
