#include <instructions/window.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <runtime.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Window::Window(Runtime& runtime): Instruction(runtime)
{
    keys = {"window"};
    keyPositions = {0};
}

void Instructions::Window::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() < 2)
    {
        Keszeg3i::error("Usage:\n\twindow open <file>\n\twindow size W H\n\twindow title <text>\n\twindow update\n\twindow close\n\twindow show");
    }

    if (args[1] == "update")
    {
        if (args.size() != 2)
        {
            Keszeg3i::error("Usage:\n\twindow update");
        }
        runtime.window.update();
    }
    else if (args[1] == "show")
    {
        if (args.size() != 2)
        {
            Keszeg3i::error("Usage:\n\twindow show");
        }
        runtime.window.show();
    }
    else if (args[1] == "close")
    {
        if (args.size() != 2)
        {
            Keszeg3i::error("Usage:\n\twindow close");
        }
        runtime.window.close();
    }
    else if (args[1] == "size")
    {
        if (args.size() != 4)
        {
            Keszeg3i::error("Usage:\n\twindow size W H");
        }
        int w = runtime.memory.isConstant(args[2]) ? stoi(args[2]): runtime.memory.getVariable(args[2]);
        int h = runtime.memory.isConstant(args[3]) ? stoi(args[3]): runtime.memory.getVariable(args[3]);
        runtime.window.size(w, h);
    }
    else if (args[1] == "open")
    {
        if (args.size() <= 2)
        {
            Keszeg3i::error("Usage:\n\twindow open <file>");
        }
        runtime.window.open(line.parseString(2));
    }
}
