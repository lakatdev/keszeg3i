#ifndef INSTRUCTIONS_DECLARE_HPP
#define INSTRUCTIONS_DECLARE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Declare : public Instruction
    {
        public:
        Declare(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
