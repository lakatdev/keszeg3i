#ifndef KESZEGUI_WINDOW_HPP
#define KESZEGUI_WINDOW_HPP

#include <string>
#include <keszegui/element.hpp>
#include <keszegui/linear.hpp>

using namespace std;

namespace KeszegUI
{
    class Window
    {
        private:
        void loopback(const string& arg);
        public:
        Linear linearMain;
        Window(const string& title, int width, int height);
        string render();
        void addElement(Element& element);
        void clear();
    };
}

#endif
