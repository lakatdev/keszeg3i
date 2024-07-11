#ifndef INSTRUCTIONS_SAVE_HPP
#define INSTRUCTIONS_SAVE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Save : public Instruction
    {
        public:
        Save(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
