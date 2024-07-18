#ifndef KESZEGUI_IMAGE_HPP
#define KESZEGUI_IMAGE_HPP

#include <keszegui/element.hpp>
#include <string>

namespace KeszegUI
{
    class Image : public Element
    {
        private:
        string& path;
        int width;
        int height;
        public:
        Image(string& path, int width, int height);
    };
}

#endif
