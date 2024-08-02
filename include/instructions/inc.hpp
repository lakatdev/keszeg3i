#ifndef INSTRUCTIONS_INC_HPP
#define INSTRUCTIONS_INC_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Inc : public Instruction
    {
        public:
        Inc(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
