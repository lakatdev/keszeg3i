g++ src/*.cpp src/instructions/*.cpp -o keszegi -I include -std=c++11 `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0`
