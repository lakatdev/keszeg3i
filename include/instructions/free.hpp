#ifndef INSTRUCTIONS_FREE_HPP
#define INSTRUCTIONS_FREE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Free : public Instruction
    {
        public:
        Free(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
