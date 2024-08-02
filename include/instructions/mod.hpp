#ifndef INSTRUCTIONS_MOD_HPP
#define INSTRUCTIONS_MOD_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Mod : public Instruction
    {
        public:
        Mod(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
