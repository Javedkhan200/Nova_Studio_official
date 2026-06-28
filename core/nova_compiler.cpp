#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

map<string, string> nova_memory;

// Kernel Engine
string execute_kernel(string cmd) {
    char buffer[128]; string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) result += buffer;
    pclose(pipe); return result;
}

// Logic Engine
void execute_line(string line) {
    smatch m;
    if (line.empty()) return;
    if (regex_search(line, m, regex(R"(Nova\.show\(\"([^\"]+)\"\))"))) { cout << m[1] << endl; }
    else if (regex_search(line, m, regex(R"(Nova\.ask\.user\(\"([a-z]+):([^\"]+)\"\))"))) {
        cout << m[2] << " "; string val; getline(cin, val); nova_memory[m[1]] = val;
    }
    else if (regex_search(line, m, regex(R"(Nova\.if\(([a-z]+)==\"([^\"]+)\")\{Nova\.show\(\"([^\"]+)\"\)\}"))) {
        if (nova_memory[m[1]] == m[2]) cout << m[3] << endl;
    }
    else if (regex_search(line, m, regex(R"(Nova\.kernel\(\"([^\"]+)\"\))"))) {
        cout << execute_kernel(m[1]);
    }
    else { cout << "SyntaxError: invalid syntax" << endl; }
}

int main() {
    // Pure Python Style Header
    cout << "Nova 110.0 (default, Jun 28 2026, 17:15:00) [Clang/LLVM C++ Core] on termux" << endl;
    cout << "Type \"help\", \"copyright\", \"credits\" or \"license\" for more information." << endl;
    
    string code;
    while (true) {
        cout << ">>> "; 
        if (!getline(cin, code) || code == "exit" || code == "quit()") break;
        stringstream ss(code); string segment;
        while (getline(ss, segment, ';')) { execute_line(segment); }
    }
    return 0;
}
