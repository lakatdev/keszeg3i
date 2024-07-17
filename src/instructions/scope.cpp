#include <instructions/scope.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Scope::Scope(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"scope"};
    keyPositions = {0};
}

void Instructions::Scope::execute(Line line)
{
    vector<string> args = line.getTokens();
    controlFlow.pushType(ControlFlow::CurrentScopeType::SCOPE);
    memory.newScope();
}
