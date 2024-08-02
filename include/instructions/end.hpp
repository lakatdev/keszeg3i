#ifndef INSTRUCTIONS_END_HPP
#define INSTRUCTIONS_END_HPP

#include <instruction.hpp>

namespace Instructions
{
    class End : public Instruction
    {
        public:
        End(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
