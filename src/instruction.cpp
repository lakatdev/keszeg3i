#include <instruction.hpp>
#include <controlflow.hpp>
#include <memory.hpp>
#include <runtime.hpp>

Instruction::Instruction(Runtime& runtime): runtime(runtime)
{

}

bool Instruction::matchesKey(Line line, string key, int keyPosition)
{
    if (length < 0)
    {
        return (line.getTokens().size() > keyPosition &&
            line.getTokens()[keyPosition] == key);
    }
    return ( length == line.getTokens().size() &&
        line.getTokens().size() > keyPosition &&
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
