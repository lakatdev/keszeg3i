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

bool ControlFlow::jumpToRt(string label)
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() >= 2 && lines[i].getTokens()[0] == "(rt" && lines[i].getTokens()[1] == label)
        {
            currentLine = i;
            executeCurrent();
            return true;
        }
    }
    return false;
}

void ControlFlow::jumpToRtEnd(string label)
{
    if (!jumpToRt(label))
    {
        return;
    }

    int i = currentLine;
    for (; i < lines.size(); i++)
    {
        if (lines[i].getTokens().size() >= 1 && lines[i].getTokens()[0] == "rt)")
        {
            currentLine = i + 1;
            break;
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

bool ControlFlow::pushJump(string label)
{
    stack.push_back(currentLine);
    return jumpToRt(label);
}

bool ControlFlow::isStackEmpty()
{
    return stack.size() == 0;
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

void ControlFlow::interrupt(string label)
{
    if (interruptLock)
    {
        Keszeg3i::debug("Interrupt lock is active");
        return;
    }
    interruptLock = true;
    int savedLine = currentLine;
    bool savedRunning = running;
    vector<int> stackCopy = stack;
    stack = vector<int>();
    if (pushJump(label))
    {
        currentExecution = false;
        while (currentLine < lines.size())
        {
            Keszeg3i::debug("Running line as interrupt " + to_string(currentLine + 1));
            interpreter.interpret(lines[currentLine], currentLine);
            if (!currentExecution)
            {
                Keszeg3i::debug("Incrementing line");
                currentLine++;
            }
            currentExecution = false;
            if (stack.size() == 0)
            {
                break;
            }
        }   
    }
    else
    {
        Keszeg3i::error("Failed to jump to " + label);
    }

    running = savedRunning;
    stack = stackCopy;
    currentLine = savedLine;
    interruptLock = false;
}
