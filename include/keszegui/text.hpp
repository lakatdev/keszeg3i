#ifndef KESZEGUI_TEXT_HPP
#define KESZEGUI_TEXT_HPP

#include <keszegui/element.hpp>
#include <string>

namespace KeszegUI
{
    class Text : public Element
    {
        private:
        string& textString;
        public:
        Text(string& textString);
    };
}

#endif
