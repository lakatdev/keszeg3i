#ifndef INSTRUCTIONS_ARRSET_HPP
#define INSTRUCTIONS_ARRSET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Arrset : public Instruction
    {
        public:
        Arrset(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
