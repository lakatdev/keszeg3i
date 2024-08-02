#ifndef INSTRUCTIONS_ARRGET_HPP
#define INSTRUCTIONS_ARRGET_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Arrget : public Instruction
    {
        public:
        Arrget(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
