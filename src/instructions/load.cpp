#include <instructions/load.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Instructions::Load::Load(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"load"};
    keyPositions = {0};
}

void Instructions::Load::loadStringFromFile(string& arr, string filename)
{
    ifstream fileStream(filename);
    if (!fileStream.is_open())
    {
        throw std::runtime_error("Could not open file " + filename);
    }
    stringstream buffer;
    buffer << fileStream.rdbuf();
    memory.setString(arr, buffer.str());
}

void Instructions::Load::loadArrayFromFile(string& arr, string filename)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file " + filename);
    }

    memory.freeArray(arr);
    int buffer;
    int i = 0;
    while (file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer)))
    {
        memory.setArrayElement(arr, i, buffer);
        i++;
    }
}

void Instructions::Load::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 4)
    {
        Keszeg3i::error("Usage: load mode X Y");
    }

    if (args[1] == "string")
    {
        loadStringFromFile(args[2], line.parseString(3));
    }
    else if (args[1] == "array")
    {
        loadArrayFromFile(args[2], line.parseString(3));
    }
    else
    {
        Keszeg3i::error("Invalid mode: " + args[1]);
    }
}
