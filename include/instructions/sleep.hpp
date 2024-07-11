#ifndef INSTRUCTIONS_SLEEP_HPP
#define INSTRUCTIONS_SLEEP_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Sleep : public Instruction
    {
        public:
        Sleep(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
