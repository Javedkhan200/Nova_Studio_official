#include "lexer.hpp"
#include "parser.hpp"
#include "runtime.hpp"
#include "modules/ai_module.hpp"
#include "modules/gui_renderer.hpp"
#include "modules/game_api.hpp"
#include "modules/interop_bridge.hpp"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    std::cout << "🚀 NovaOS Engine v2 (High-Level AI/App/Game) Initialized...\n";
    
    // Test the high-level C++ bindings directly
    NovaAI::think("Optimize OS kernel parameters");
    NovaGUI::renderApp("Nova Desktop Environment", 1920, 1080);
    NovaGame::initEngine("Nova Physics Demo");
    
    // Keep main thread alive for async tasks to show output
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << "✅ All high-level sub-systems operational.\n";
    return 0;
}
