#ifndef INSTRUCTIONS_ADD_HPP
#define INSTRUCTIONS_ADD_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Add : public Instruction
    {
        public:
        Add(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
