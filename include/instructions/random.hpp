#ifndef INSTRUCTIONS_RANDOM_HPP
#define INSTRUCTIONS_RANDOM_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Random : public Instruction
    {
        public:
        Random(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
