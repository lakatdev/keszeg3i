#ifndef INSTRUCTIONS_SAVE_HPP
#define INSTRUCTIONS_SAVE_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Save : public Instruction
    {
        private:
        void saveStringToFile(const string& str, const string& filename);
        void saveArrayToFile(const string& arr, const string& filename);
        public:
        Save(ControlFlow& controlFlow, Memory& memory);
        void execute(Line line);
    };
}

#endif
