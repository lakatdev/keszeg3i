#ifndef INSTRUCTIONS_STRSET_HPP
#define INSTRUCTIONS_STRSET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Strset : public Instruction
    {
        public:
        Strset(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
