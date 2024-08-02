#ifndef INSTRUCTIONS_INPUT_HPP
#define INSTRUCTIONS_INPUT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Input : public Instruction
    {
        public:
        Input(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
