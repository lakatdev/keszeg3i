#ifndef INSTRUCTIONS_LOAD_HPP
#define INSTRUCTIONS_LOAD_HPP

#include <instruction.hpp>

namespace Instructions
{
    class Load : public Instruction
    {
        private:
        void loadStringFromFile(string& arr, string filename);
        void loadArrayFromFile(string& arr, string filename);
        public:
        Load(Runtime& runtime);
        void execute(Line line);
    };
}

#endif
