#include <keszegui/window.hpp>
#include <keszegui/element.hpp>
#include <keszegui/webview.h>
#include <string>
#include <iostream>

using namespace std;

KeszegUI::Window::Window(ControlFlow& controlFlow, const string& title, int width, int height)
{
    this.controlFlow = controlFlow;
    linearMain.setOrientation(Linear::Orientation::VERTICAL);
    linearMain.setAlignment(Linear::Alignment::START);
}

void KeszegUI::Window::loopback(const string& arg)
{
    if (arg.length() > 4)
    {
        arg = arg.substr(2, arg.length() - 4);
        controlFlow.pushJump(arg); // Ez lehet nem fog mukodni TODO
    }
}

void KeszegUI::Window::render()
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

    w.navigate("data:text/html," + string(html));
    w.run();
}

void KeszegUI::Window::addElement(KeszegUI::Element& element)
{
    linearMain.addElement(element);
}

void KeszegUI::Window::clear()
{
    linearMain.clear();
}
