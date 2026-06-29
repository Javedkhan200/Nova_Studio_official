#ifndef AI_MODULE_HPP
#define AI_MODULE_HPP

#include <iostream>
#include <string>
#include <thread>
#include <future>

class NovaAI {
public:
    // High-level async think function
    static void think(const std::string& prompt) {
        std::thread([prompt]() {
            std::cout << "[Nova AI] Thinking about: " << prompt << "...\n";
            // Simulated async HTTP call to Gemini/OpenAI API
            std::this_thread::sleep_for(std::chrono::seconds(2)); 
            std::cout << "[Nova AI Response] Execution strategy for '" << prompt << "' is ready.\n";
        }).detach();
    }
};

#endif
