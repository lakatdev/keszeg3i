#ifndef KESZEGUI_WINDOW_HPP
#define KESZEGUI_WINDOW_HPP

#include <string>
#include <controlflow.hpp>
#include <memory.hpp>
#include <keszegui/webview.h>

using namespace std;

namespace KeszegUI
{
    class Window
    {
        private:
        webview::webview w;
        ControlFlow& controlFlow;
        Memory& memory;
        string content;
        string fileContent;
        void loopback(const string& arg);
        public:
        Window(ControlFlow& controlFlow, Memory& memory);
        void update();
        void close();
        void size(int width, int height);
        void open(const string& path);
        void show();
        void title(const string& title);
    };
}

#endif
