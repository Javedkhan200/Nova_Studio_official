#ifndef INTEROP_BRIDGE_HPP
#define INTEROP_BRIDGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class NovaBridge {
public:
    static void runPython(const std::string& scriptName) {
        std::cout << "[Nova Bridge] Executing Python script: " << scriptName << "\n";
        std::string cmd = "python3 " + scriptName;
        std::system(cmd.c_str());
    }

    static void runNode(const std::string& scriptName) {
        std::cout << "[Nova Bridge] Executing Node.js script: " << scriptName << "\n";
        std::string cmd = "node " + scriptName;
        std::system(cmd.c_str());
    }
};

#endif
