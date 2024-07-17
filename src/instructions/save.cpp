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
    if (args.size() != 3)
    {
        Keszeg3i::error("Usage: save X Y");
    }

    if (memory.isString(args[1]))
    {
        saveStringToFile(memory.getString(args[1]), line.parseString(2));
    }
    else if (memory.isArray(args[1]))
    {
        saveArrayToFile(args[1], line.parseString(2));
    }
    else
    {
        Keszeg3i::error("Variable is not a string or an array");
    }
}
