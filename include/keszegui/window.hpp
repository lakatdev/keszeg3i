#ifndef KESZEGUI_WINDOW_HPP
#define KESZEGUI_WINDOW_HPP

#include <string>
#include <controlflow.hpp>

using namespace std;

namespace KeszegUI
{
    class Window
    {
        private:
        ControlFlow& controlFlow;
        string content;
        void loopback(const string& arg);
        public:
        Window(ControlFlow& controlFlow, const string& title, int width, int height, const string& path);
    };
}

#endif
