#include <keszegui/window.hpp>
#include <keszegui/webview.h>
#include <string>
#include <iostream>
#include <fstream>
#include <keszeg3i.hpp>
#include <sstream>
#include <regex>

using namespace std;

KeszegUI::Window::Window(ControlFlow& controlFlow, Memory& memory): controlFlow(controlFlow), memory(memory), w(true, nullptr)
{

}

void KeszegUI::Window::update()
{
    content = fileContent;

    regex routinePattern("&\\(rt\\s+(\\w+)\\)");
    string routineReplacement = "\"loopback(\'$1\')\"";
    content = regex_replace(content, routinePattern, routineReplacement);

    regex stringPattern("&\\(string\\s+(\\w+)\\)");
    string result;
    auto begin = sregex_iterator(content.begin(), content.end(), stringPattern);
    auto end = sregex_iterator();
    size_t lastPos = 0;

    for (auto it = begin; it != end; ++it)
    {
        smatch match = *it;
        result += content.substr(lastPos, match.position() - lastPos);
        result += memory.getString(match[1].str());
        lastPos = match.position() + match.length();
    }
    result += content.substr(lastPos);

    content = result;

    w.bind("loopback", [this](const string& arg) -> string
    {
        this->loopback(arg);
        return "";
    });

    Keszeg3i::debug("Content: " + content);
    w.navigate("data:text/html," + content);
}

void KeszegUI::Window::close()
{
    w.terminate();
}

void KeszegUI::Window::size(int width, int height)
{
    w.set_size(width, height, WEBVIEW_HINT_NONE);
}

void KeszegUI::Window::open(const string& path)
{
    ifstream file(path);
    if (file)
    {
        stringstream buffer;
        buffer << file.rdbuf();
        fileContent = buffer.str();
    }
    else
    {
        Keszeg3i::error("Failed to open file at " + path);
        return;
    }
}

void KeszegUI::Window::show()
{
    w.run();
}

void KeszegUI::Window::title(const string& title)
{
    w.set_title(title);
}

void KeszegUI::Window::loopback(const string& arg)
{
    if (arg.length() > 4)
    {
        string rt = arg.substr(2, arg.length() - 4);
        Keszeg3i::debug("Loopback: " + rt);
        controlFlow.interrupt(rt);
    }
}
