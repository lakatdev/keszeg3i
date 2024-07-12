#include <controlflow.hpp>
#include <interpreter.hpp>
#include <keszeg3i.hpp>

using namespace std;

ControlFlow::ControlFlow(Interpreter& interpreter): interpreter(interpreter)
{
    currentLine = 0;
}

void ControlFlow::addLine(Line line)
{
    lines.push_back(line);
}

void ControlFlow::run()
{
    running = true;
    currentLine = 0;
    jumpToRt("MAIN");
    while (running && currentLine < lines.size())
    {
        Keszeg3i::debug("Running line " + to_string(currentLine + 1));
        interpreter.interpret(lines[currentLine], currentLine);
        if (!currentExecution)
        {
            currentLine++;
        }
        currentExecution = false;
    }
    running = false;
}

void ControlFlow::executeCurrent()
{
    currentExecution = true;
}

void ControlFlow::jumpToRt(string label)
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() >= 2 && lines[i].getTokens()[0] == "(rt" && lines[i].getTokens()[1] == label)
        {
            currentLine = i;
            executeCurrent();
            return;
        }
    }
}

void ControlFlow::jumpToEnd()
{
    int newScopes = 1;
    for (int i = currentLine + 1; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() < 1)
        {
            continue;
        }

        if (lines[i].getTokens()[0] == "if")
        {
            newScopes++;
        }
        else if (lines[i].getTokens()[0] == "while")
        {
            newScopes++;
        }
        else if (lines[i].getTokens()[0] == "scope")
        {
            newScopes++;
        }
        else if (lines[i].getTokens()[0] == "end")
        {
            newScopes--;
        }
        if (newScopes == 0)
        {
            currentLine = i;
            return;
        }
    }
}

ControlFlow::CurrentScopeType ControlFlow::getCurrentScopeType()
{
    return currentScope[currentScope.size() - 1];
}

void ControlFlow::pushJump(string label)
{
    stack.push_back(currentLine);
    jumpToRt(label);
}

void ControlFlow::popJump()
{
    if (stack.size() == 0)
    {
        running = false;
        return;
    }
    int line = stack[stack.size() - 1];
    stack.pop_back();
    currentLine = line;
}

void ControlFlow::pushType(CurrentScopeType type)
{
    currentScope.push_back(type);
    Keszeg3i::debug("Pushed scope, size: " + to_string(currentScope.size()) + " line " + to_string(currentLine + 1));
}

ControlFlow::CurrentScopeType ControlFlow::popType()
{
    if (currentScope.size() > 0)
    {
        CurrentScopeType type = currentScope[currentScope.size() - 1];
        currentScope.pop_back();
        Keszeg3i::debug("Popped scope, size: " + to_string(currentScope.size()) + " line " + to_string(currentLine + 1));
        return type;
    }
    Keszeg3i::error("No scope to pop on line " + to_string(currentLine + 1));
    return NONE;
}

void ControlFlow::jumpToScopeStart()
{
    int newScopes = 1;
    for (int i = currentLine - 1; i > 0; i--)
    {
        if (lines[i].getTokens().size() < 1)
        {
            continue;
        }
        if (lines[i].getTokens()[0] == "if")
        {
            newScopes--;
        }
        else if (lines[i].getTokens()[0] == "while")
        {
            newScopes--;
        }
        else if (lines[i].getTokens()[0] == "scope")
        {
            newScopes--;
        }
        else if (lines[i].getTokens()[0] == "end")
        {
            newScopes++;
        }
        if (newScopes == 0)
        {
            currentLine = i;
            executeCurrent();
            return;
        }
    }
}

