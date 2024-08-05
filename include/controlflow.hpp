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
    bool currentExecution = false;
    void executeCurrent();

    public:
    ControlFlow(Interpreter& interpreter);
    void addLine(Line line);
    void run();

    bool jumpToRt(string label);
    void jumpToEnd();
    void jumpToScopeStart();
    CurrentScopeType getCurrentScopeType();
    bool pushJump(string label);
    void popJump();
    void pushType(CurrentScopeType type);
    void interrupt(string label);
    CurrentScopeType popType();
};

#endif
