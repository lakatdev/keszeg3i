#ifndef INSTRUCTIONS_RETURN_HPP
#define INSTRUCTIONS_RETURN_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Return : public Instruction
    {
        public:
        Return(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
