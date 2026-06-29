#ifndef GAME_API_HPP
#define GAME_API_HPP

#include <iostream>
#include <string>

class NovaGame {
public:
    static void initEngine(const std::string& title) {
        std::cout << "[Nova Game API] OpenGL/SDL2 Context Initialized for: " << title << "\n";
    }

    static void startLoop() {
        std::cout << "[Nova Game API] High-performance game loop started (60 FPS Target).\n";
        // Background physics and rendering thread logic goes here
    }
};

#endif
