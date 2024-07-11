#ifndef CONTROLFLOW_HPP
#define CONTROLFLOW_HPP

#include <interpreter.hpp>
#include <line.hpp>

class ControlFlow
{
    public:
    enum CurrentScopeType
    {
        NONE,
        WHILE,
        IF,
        SCOPE
    };

    private:
    Interpreter& interpreter;
    vector<Line> lines;
    int currentLine;
    vector<CurrentScopeType> currentScope;
    vector<int> stack;
    bool running = false;

    public:
    ControlFlow(Interpreter& interpreter);
    void addLine(Line line);
    void run();

    void jumpToRt(string label);
    void jumpToEnd();
    void jumpToScopeStart();
    CurrentScopeType getCurrentScopeType();
    void pushJump(string label);
    void popJump();
    void pushType(CurrentScopeType type);
    CurrentScopeType popType();
};

#endif
