#include <instructions/save.hpp>
#include <keszeg3i.hpp>
#include <memory.hpp>
#include <controlflow.hpp>
#include <fstream>
#include <string>

using namespace std;

Instructions::Save::Save(ControlFlow& controlFlow, Memory& memory): Instruction(controlFlow, memory)
{
    keys = {"save"};
    keyPositions = {0};
}

void Instructions::Save::saveStringToFile(const string& str, const string& filename)
{
    std::ofstream file(filename, ios::binary);
    if (file.is_open())
    {
        file.write(str.data(), str.size());
        file.close();
    }
    else
    {
        Keszeg3i::error("Could not open file");
    }
}

void Instructions::Save::saveArrayToFile(const string& arr, const string& filename)
{
    ofstream file(filename, ios::binary);
    if (file.is_open())
    {
        for (int i = 0; i < memory.getArraySize(arr); i++)
        {
            int element = memory.getArrayElement(arr, i);
            file.write(reinterpret_cast<const char*>(&element), sizeof(element));
        }
        file.close();
    } 
    else
    {
        Keszeg3i::error("Could not open file");
    }
}

void Instructions::Save::execute(Line line)
{
    vector<string> args = line.getTokens();
    if (args.size() != 4)
    {
        Keszeg3i::error("Usage: save mode X Y");
    }

    if (args[1] == "string")
    {
        if (memory.isString(args[2]))
        {
            saveStringToFile(memory.getString(args[2]), line.parseString(3));
        }
        else
        {
            Keszeg3i::error("Variable is not a string");
        }
    }
    else if (args[1] == "array")
    {
        if (memory.isArray(args[2]))
        {
            saveArrayToFile(args[2], line.parseString(3));
        }
        else
        {
            Keszeg3i::error("Variable is not an array");
        }
    }
    else
    {
        Keszeg3i::error("Invalid mode: " + args[1]);
    }
}
