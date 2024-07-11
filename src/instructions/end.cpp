#include <instructions/end.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::End::End(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"end"};
    keyPositions = {0};
}

void Instructions::End::execute(Line line)
{
    vector<string> args = line.getTokens();
    ControlFlow::CurrentScopeType endedScope = controlFlow.popType();
    switch (endedScope)
    {
        case (ControlFlow::CurrentScopeType::IF):
        {
            break;
        }
        case (ControlFlow::CurrentScopeType::WHILE):
        {
            controlFlow.jumpToScopeStart();
            break;
        }
        case (ControlFlow::CurrentScopeType::SCOPE):
        {
            memory.endScope();
            break;
        }
    }
}
