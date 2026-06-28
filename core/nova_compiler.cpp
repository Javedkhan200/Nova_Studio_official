#include <iostream>
#include <string>
#include <regex>
using namespace std;
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define YELLOW "\033[1;33m"
int main() {
    cout << CYAN << "Nova 110.0 | Copyright (c) 2026 Nova Studio. All Rights Reserved." << RESET << endl;
    cout << "Type \"help\", \"copyright\", \"credits\" or \"license\"." << endl;
    string code;
    while (true) {
        cout << YELLOW << ">>> " << RESET;
        if (!getline(cin, code) || code == "exit") break;
        if (code == "copyright") cout << "Copyright (c) 2026 Nova Studio. All Rights Reserved.\n";
        else if (code == "credits") cout << "Architect: Javed. Nova Engine v110.\n";
        else if (code == "license") cout << "Released under Nova Universal License.\n";
        else cout << "Nova Syntax Engine Ready. Input: " << code << endl;
    }
    return 0;
}
