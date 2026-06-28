#include <iostream>
#include <string>
#include <regex>
using namespace std;
void execute_line(string line) {
    if (line == "copyright") { cout << "Copyright (c) 2026 Nova Studio. All Rights Reserved.\n"; return; }
    if (line == "credits") { cout << "Architect: Javed. Engine v110.\n"; return; }
    if (line == "license") { cout << "Nova Universal License.\n"; return; }
    if (line.find("Nova.show") != string::npos) { cout << line.substr(line.find("\"")+1, line.find_last_of("\"") - line.find("\"") - 1) << endl; }
}
int main() {
    cout << "Nova 110.0 [Stable]. Type 'copyright', 'credits', or 'license'.\n>>> ";
    string code;
    while(getline(cin, code)) { execute_line(code); cout << ">>> "; }
    return 0;
}
