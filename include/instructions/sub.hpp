#ifndef INSTRUCTIONS_SUB_HPP
#define INSTRUCTIONS_SUB_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Sub : public Instruction
    {
        public:
        Sub(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
