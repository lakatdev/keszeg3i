#ifndef INSTRUCTIONS_FREE_HPP
#define INSTRUCTIONS_FREE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Free : public Instruction
    {
        public:
        Free(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
