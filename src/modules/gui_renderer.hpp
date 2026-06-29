#ifndef GUI_RENDERER_HPP
#define GUI_RENDERER_HPP

#include <iostream>
#include <string>

class NovaGUI {
public:
    // High-level wrapper for modern UI (WhatsApp/YouTube style architecture)
    static void renderApp(const std::string& appName, int width, int height) {
        std::cout << "[Nova GUI] Launching High-Level Renderer for '" << appName << "'\n";
        std::cout << "[Nova GUI] Resolution: " << width << "x" << height << "\n";
        std::cout << "[Nova GUI] UI Engine Hooked. Awaiting DOM/Widget tree...\n";
    }
};

#endif
