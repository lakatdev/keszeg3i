#ifndef INSTRUCTIONS_STRGET_HPP
#define INSTRUCTIONS_STRGET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Strget : public Instruction
    {
        public:
        Strget(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
