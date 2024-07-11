#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>
#include <line.hpp>

class Memory;
class ControlFlow;

using namespace std;

class Instruction
{
    private:
    bool matchesKey(Line line, string key, int keyPosition);
    protected:
    Memory& memory;
    ControlFlow& controlFlow;
    vector<string> keys;
    vector<int> keyPositions;
    public:
    Instruction(ControlFlow& controlFlow, Memory& runtime);
    virtual void execute(Line line) = 0;
    bool matches(Line line);
};

#endif
