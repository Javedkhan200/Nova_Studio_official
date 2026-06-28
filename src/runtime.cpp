#include "runtime.hpp"
#include <iostream>
#include <regex>

void Runtime::executeLine(const std::string& line) {
    if (line.empty() || line[0] == '#') return;
    
    // Nova.ask.user (Regex escaped for C++ compatibility)
    std::regex ask_regex("Nova\\.ask\\.user\\(\"([^\"]+):\"\\s+\"([^\"]+)\"\\)");
    std::smatch m;
    if (std::regex_search(line, m, ask_regex)) {
        std::cout << m[2] << " ";
        std::string input; std::getline(std::cin, input);
        variables[m[1]] = input;
        return;
    }

    // Nova.show("text")
    std::regex show_str("Nova\\.show\\(\"([^\"]+)\"\\)");
    if (std::regex_search(line, m, show_str)) {
        std::cout << m[1] << std::endl; return;
    }

    // Nova.show(variable)
    std::regex show_var("Nova\\.show\\(([a-zA-Z0-9_]+)\\)");
    if (std::regex_search(line, m, show_var)) {
        std::cout << variables[m[1]] << std::endl; return;
    }

    // Nova.import
    std::regex imp_regex("Nova\\.import\\(\"([^\"]+)\"\\)");
    if (std::regex_search(line, m, imp_regex)) {
        std::cout << "[Nova Loader] Linking Library: " << m[1] << "..." << std::endl;
        std::string cmd = "pkg install " + m[1].str() + " -y > /dev/null 2>&1";
        std::system(cmd.c_str());
        return;
    }

    // Assignments
    std::regex assign_regex("([a-zA-Z_][a-zA-Z0-9_]*)\\s*=\\s*(.+)");
    if (std::regex_search(line, m, assign_regex)) {
        variables[m[1]] = m[2]; return;
    }

    // Shell Execution
    std::system(line.c_str());
}
