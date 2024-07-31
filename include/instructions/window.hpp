#ifndef INSTRUCTIONS_WINDOW_HPP
#define INSTRUCTIONS_WINDOW_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Window : public Instruction
    {
        public:
        Window(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
