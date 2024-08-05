#include <keszegui/window.hpp>
#include <keszegui/webview.h>
#include <string>
#include <iostream>
#include <fstream>
#include <keszeg3i.hpp>
#include <sstream>
#include <regex>

using namespace std;

KeszegUI::Window::Window(ControlFlow& controlFlow, const string& title, int width, int height, const string& path): controlFlow(controlFlow), w(true, nullptr)
{
    open(path);
    this->title(title);
    size(width, height);
    update();
    show();
}

KeszegUI::Window::Window(ControlFlow& controlFlow): controlFlow(controlFlow), w(true, nullptr)
{

}

void KeszegUI::Window::update()
{
    regex pattern("&\\(rt\\s+(\\w+)\\)");
    string replacement = "\"loopback(\'$1\')\"";

    content = regex_replace(content, pattern, replacement);

    w.bind("loopback", [this](const string& arg) -> string
    {
        this->loopback(arg);
        return "";
    });

    cout << "Content: " << content << endl;

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
        content = buffer.str();
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
        cout << "Loopback: " << rt << endl;
        controlFlow.interrupt(rt);
    }
}
