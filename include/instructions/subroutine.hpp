#ifndef INSTRUCTIONS_SUBROUTINE_HPP
#define INSTRUCTIONS_SUBROUTINE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Subroutine : public Instruction
    {
        public:
        Subroutine(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
