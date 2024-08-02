#ifndef INSTRUCTIONS_SIZEOF_HPP
#define INSTRUCTIONS_SIZEOF_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Sizeof : public Instruction
    {
        public:
        Sizeof(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
