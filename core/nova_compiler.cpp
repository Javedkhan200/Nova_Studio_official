#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;
map<string, string> nova_memory;
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define YELLOW "\033[1;33m"

void execute_line(string line) {
    smatch m;
    if (line == "copyright") { cout << "Copyright (c) 2026 Nova Studio. All Rights Reserved.\n"; return; }
    if (line == "credits") { cout << "Architect: Javed. Engine v110.\n"; return; }
    if (line == "license") { cout << "Released under Nova Universal License.\n"; return; }
    
    if (regex_search(line, m, regex(R"(Nova\.ask\.user\(\"([a-zA-Z0-9_]+):\"(.*)\))"))) {
        cout << m[2] << " "; string val; getline(cin, val); nova_memory[m[1]] = val;
    }
    else if (regex_search(line, m, regex(R"(Nova\.show\(\"([^\"]+)\"\))"))) { cout << m[1] << endl; }
    else if (regex_search(line, m, regex(R"(Nova\.show\(([a-zA-Z0-9_]+)\))"))) { cout << nova_memory[m[1]] << endl; }
    else if (!line.empty()) { cout << "SyntaxError: Nova nahi samajh paya!" << endl; }
}
int main() {
    cout << CYAN << "Nova 110.0 [Advanced Syntax] Ready." << RESET << endl;
    string code;
    while (true) {
        cout << YELLOW << ">>> " << RESET;
        if (!getline(cin, code) || code == "exit") break;
        execute_line(code);
    }
    return 0;
}
