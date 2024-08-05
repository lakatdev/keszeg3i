#include "scope.hpp"
#include <string>
#include <line.hpp>
#include <vector>
#include <interpreter.hpp>
#include <runtime.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

void Runtime::readLines(string source)
{
    ifstream file(source);
    stringstream buffer;

    if (file)
    {
        buffer << file.rdbuf();
    }

    string line;
    while (getline(buffer, line))
    {
        controlFlow.addLine(Line(line));
    }
}

Runtime::Runtime(ControlFlow& controlFlow, Memory& memory, KeszegUI::Window& window, string source)
    : memory(memory), controlFlow(controlFlow), window(window)
{
    srand(time(nullptr));
    readLines(source);
}

void Runtime::run()
{
    controlFlow.run();
}
