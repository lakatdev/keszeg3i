#ifndef KESZEGUI_LINEAR_HPP
#define KESZEGUI_LINEAR_HPP

#include <vector>
#include <keszegui/element.hpp>

using namespace std;

namespace KeszegUI
{
    class Linear : public Element
    {
        private:
        enum Orientation
        {
            HORIZONTAL,
            VERTICAL
        };
        enum Alignment
        {
            START,
            CENTER,
            END
        };
        vector<Element> elements;
        Alignment alignment;
        Orientation orientation;
        public:
        void addElement(Element element);
        void clear();
        void setAlignment(Alignment alignment);
        void setOrientation(Orientation orientation);
    };
}

#endif
