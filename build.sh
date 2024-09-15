g++ src/*.cpp src/instructions/*.cpp src/keszegui/*.cpp -o keszegi -I include -std=c++11 `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0`

# needed to run: apt install libgtk-3-0 libwebkit2gtk-4.0-37
# needed to compile: apt install libgtk-3-dev libwebkit2gtk-4.0-dev
