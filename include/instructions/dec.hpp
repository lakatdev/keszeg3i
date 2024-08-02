#ifndef INSTRUCTIONS_DEC_HPP
#define INSTRUCTIONS_DEC_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Dec : public Instruction
    {
        public:
        Dec(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
