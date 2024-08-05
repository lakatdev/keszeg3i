#ifndef KESZEGUI_WINDOW_HPP
#define KESZEGUI_WINDOW_HPP

#include <string>
#include <controlflow.hpp>
#include <keszegui/webview.h>

using namespace std;

namespace KeszegUI
{
    class Window
    {
        private:
        webview::webview w;
        ControlFlow& controlFlow;
        string content;
        void loopback(const string& arg);
        public:
        Window(ControlFlow& controlFlow, const string& title, int width, int height, const string& path);
        Window(ControlFlow& controlFlow);
        void update();
        void close();
        void size(int width, int height);
        void open(const string& path);
        void show();
        void title(const string& title);
    };
}

#endif
