#ifndef INSTRUCTIONS_PRINT_HPP
#define INSTRUCTIONS_PRINT_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Print : public Instruction
    {
        public:
        Print(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
