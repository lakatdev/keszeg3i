#include <instructions/scope.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <runtime.hpp>

using namespace std;

Instructions::Scope::Scope(Runtime& runtime): Instruction(runtime)
{
    keys = {"scope"};
    keyPositions = {0};
}

void Instructions::Scope::execute(Line line)
{
    vector<string> args = line.getTokens();
    runtime.controlFlow.pushType(ControlFlow::CurrentScopeType::SCOPE);
    runtime.memory.newScope();
}
