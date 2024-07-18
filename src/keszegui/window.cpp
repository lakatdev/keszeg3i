#include <keszegui/window.hpp>
#include <keszegui/element.hpp>
#include <keszegui/webview.h>
#include <string>
#include <iostream>

using namespace std;

KeszegUI::Window::Window(const string& title, int width, int height)
{
    webview::webview w(true, nullptr);
    w.set_title(title);
    w.set_size(width, height, WEBVIEW_HINT_NONE);

    string html = "<!doctype html><html><body><h1>Hello, World!</h1><p>This is a simple HTML page displayed in a WebView.</p><button onclick=\"test_fung('func')\">test</button></body></html>";

    w.bind("test_fung", [this](const std::string& arg) -> std::string
    {
        this->loopback(arg);
        return "";
    });

    w.navigate("data:text/html," + string(html));
    w.run();
}

void KeszegUI::Window::loopback(const string& arg)
{
    cout << "loopback: " << arg << endl;
}

string KeszegUI::Window::render()
{
    return "";
}

void KeszegUI::Window::addElement(KeszegUI::Element& element)
{

}

void KeszegUI::Window::clear()
{

}
