#include <instruction.hpp>
#include <controlflow.hpp>
#include <memory.hpp>

Instruction::Instruction(ControlFlow& controlFlow, Memory& memory): memory(memory), controlFlow(controlFlow)
{

}

bool Instruction::matchesKey(Line line, string key, int keyPosition)
{
    return (line.getTokens().size() > keyPosition &&
        line.getTokens()[keyPosition] == key);
}

bool Instruction::matches(Line line)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (!matchesKey(line, keys[i], keyPositions[i]))
        {
            return false;
        }
    }
    return true;
}
