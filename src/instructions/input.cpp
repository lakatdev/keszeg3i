#include <instructions/input.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <iostream>

using namespace std;

Instructions::Input::Input(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"input"};
    keyPositions = {0};
}

void Instructions::Input::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: input mode X");
    }

    if (args[1] == "$")
    {
        int val = 0;
        cin >> val;
        memory.setVariable(args[2], val);
    }
    else if (args[1] == "ascii")
    {
        char valChar;
        cin >> valChar;
        int val = valChar;
        memory.setVariable(args[2], val);
    }
    else if (args[1] == "string")
    {
        string val;
        cin >> val;
        memory.setString(args[2], val);
    }
    else
    {
        Keszeg3i::error("Invalid mode: " + args[1]);
    }
}
