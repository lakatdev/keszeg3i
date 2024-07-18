#ifndef KESZEGUI_BUTTON_HPP
#define KESZEGUI_BUTTON_HPP

#include <keszegui/element.hpp>
#include <string>

namespace KeszegUI
{
    class Button : public Element
    {
        private:
        string& textString;
        string& function;
        public:
        Button(string& textString, string& function);
    };
}

#endif
