#ifndef INSTRUCTIONS_SCOPE_HPP
#define INSTRUCTIONS_SCOPE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Scope : public Instruction
    {
        public:
        Scope(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
