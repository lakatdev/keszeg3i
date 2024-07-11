#include <controlflow.hpp>
#include <interpreter.hpp>

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
    while (running)
    {
        interpreter.interpret(lines[currentLine], currentLine);
        currentLine++;
    }
}

void ControlFlow::jumpToRt(string label)
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() >= 2 && lines[i].getTokens()[0] == "(rt" && lines[i].getTokens()[1] == label)
        {
            currentLine = i;
            return;
        }
    }
}

void ControlFlow::jumpToEnd()
{
    for (int i = currentLine + 1; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() < 1)
        {
            continue;
        }

        int newScopes = 1;
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
}

ControlFlow::CurrentScopeType ControlFlow::popType()
{
    CurrentScopeType type = currentScope[currentScope.size() - 1];
    currentScope.pop_back();
    return type;
}

void ControlFlow::jumpToScopeStart()
{
    for (int i = currentLine; i > 0; i--)
    {
        int newScopes = 1;
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
            return;
        }
    }
}

