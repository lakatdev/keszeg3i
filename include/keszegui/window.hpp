#ifndef KESZEGUI_WINDOW_HPP
#define KESZEGUI_WINDOW_HPP

#include <string>
#include <keszegui/element.hpp>
#include <keszegui/linear.hpp>
#include <controlflow.hpp>

using namespace std;

namespace KeszegUI
{
    class Window
    {
        private:
        ControlFlow& controlFlow;
        void loopback(const string& arg);
        public:
        Linear linearMain;
        Window(ControlFlow& controlFlow, const string& title, int width, int height);
        void render();
        void addElement(Element& element);
        void clear();
    };
}

#endif
