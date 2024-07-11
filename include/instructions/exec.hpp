#ifndef INSTRUCTIONS_EXEC_HPP
#define INSTRUCTIONS_EXEC_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Exec : public Instruction
    {
        public:
        Exec(ControlFlow& controlFlow, Memory& memory);
        void execute(vector<string> args);
    };
}

#endif
