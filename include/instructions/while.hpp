#ifndef INSTRUCTIONS_WHILE_HPP
#define INSTRUCTIONS_WHILE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class While : public Instruction
    {
        public:
        While(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
