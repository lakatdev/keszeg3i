#ifndef INSTRUCTIONS_CALL_HPP
#define INSTRUCTIONS_CALL_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Call : public Instruction
    {
        public:
        Call(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
