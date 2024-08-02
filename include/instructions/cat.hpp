#ifndef INSTRUCTIONS_CAT_HPP
#define INSTRUCTIONS_CAT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Cat : public Instruction
    {
        public:
        Cat(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
