#include <instructions/end.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <runtime.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::End::End(Runtime& runtime): Instruction(runtime)
{
    keys = {"end"};
    keyPositions = {0};
}

void Instructions::End::execute(Line line)
{
    vector<string> args = line.getTokens();
    ControlFlow::CurrentScopeType endedScope = runtime.controlFlow.popType();
    switch (endedScope)
    {
        case (ControlFlow::CurrentScopeType::IF):
        {
            break;
        }
        case (ControlFlow::CurrentScopeType::WHILE):
        {
            runtime.controlFlow.jumpToScopeStart();
            break;
        }
        case (ControlFlow::CurrentScopeType::SCOPE):
        {
            runtime.memory.endScope();
            break;
        }
    }
}
