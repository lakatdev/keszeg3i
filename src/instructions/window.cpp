#include <instructions/window.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>

using namespace std;

Instructions::Window::Window(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
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
    
    }
    else if (args[1] == "show")
    {

    }
    else if (args[1] == "close")
    {

    }
    else if (args[1] == "size")
    {

    }
    else if (args[1] == "open")
    {

    }
}
