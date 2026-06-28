#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define YELLOW "\033[1;33m"

void show_copyright() { cout << CYAN << "Nova 110.0 | Copyright (c) 2026 Nova Studio. All Rights Reserved." << RESET << endl; }

int main() {
    show_copyright();
    cout << "Type \"help\", \"copyright\", \"credits\" or \"license\"." << endl;
    string code;
    while (true) {
        cout << YELLOW << ">>> " << RESET;
        if (!getline(cin, code) || code == "exit") break;
        
        // Meta Commands
        if (code == "copyright") show_copyright();
        else if (code == "credits") cout << "Architect: Javed. Nova Engine v110.\n";
        else if (code == "license") cout << "Released under Nova Universal License.\n";
        
        // Nova Syntax: Nova.show("text")
        else if (regex_match(code, regex(R"(Nova\.show\(\"([^\"]+)\"\))"))) {
            smatch m; regex_search(code, m, regex(R"(\"([^\"]+)\")"));
            cout << m[1] << endl;
        }
        // Math Logic: 345+457
        else if (regex_match(code, regex(R"(\d+\+\d+)"))) {
            int a, b; char op; stringstream ss(code); ss >> a >> op >> b;
            cout << a + b << endl;
        }
        else { cout << "Nova Engine: Input received -> " << code << endl; }
    }
    return 0;
}
