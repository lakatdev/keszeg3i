#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>
#include <line.hpp>

class Runtime;

using namespace std;

class Instruction
{
    private:
    bool matchesKey(Line line, string key, int keyPosition);
    protected:
    Runtime& runtime;
    vector<string> keys;
    vector<int> keyPositions;
    int length = -1;
    public:
    Instruction(Runtime& runtime);
    virtual void execute(Line line) = 0;
    bool matches(Line line);
};

#endif
