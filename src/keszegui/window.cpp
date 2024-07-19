#include <keszegui/window.hpp>
#include <string>
#include <keszegui/webview.h>
#include <iostream>
#include <fstream>
#include <keszeg3i.hpp>
#include <sstream>

using namespace std;

KeszegUI::Window::Window(ControlFlow& controlFlow, const string& title, int width, int height, const string& path): controlFlow(controlFlow)
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

    webview::webview w(true, nullptr);
    w.set_title(title);
    w.set_size(width, height, WEBVIEW_HINT_NONE);

    // &\(rt\s+(\w+)\)

    //content = "<!doctype html><body><p>hello world</p></body></html>";
    cout << "data:text/html," + string(content) << endl;

    w.navigate("data:text/html," + string(content));
    w.run();
}

void KeszegUI::Window::loopback(const string& arg)
{
    if (arg.length() > 4)
    {
        string rt = arg.substr(2, arg.length() - 4);
        controlFlow.pushJump(rt); // Ez lehet nem fog mukodni TODO
        // TODO ezert lehet fel kell parameterezni hogy a
        // return tudja hogy igazabol nem kell visszaugrania vagy
        // ha igen akkor csak a window render instructionre amit nem kell ujbol lefuttatnia


    }
}

/*void KeszegUI::Window::render()
{
    webview::webview w(true, nullptr);
    w.set_title(title);
    w.set_size(width, height, WEBVIEW_HINT_NONE);

    string html = "<!doctype html><body>";
    html += linearMain.render();
    html += "</body></html>";

    string html = render();

    w.bind("test_fung", [this](const std::string& arg) -> std::string
    {
        this->loopback(arg);
        return "";
    });

    
}*/
