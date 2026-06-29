#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include "parser.hpp"
#include <unordered_map>
#include <cstdlib>
#include <thread>
#include <mutex>

class NovaRuntime {
private:
    std::unordered_map<std::string, std::string> memory;
    std::mutex mem_mutex;

    // OS Level Call (Termux/Linux Native)
    void executeSystemCommand(const std::string& cmd) {
        int result = std::system(cmd.c_str());
        if (result != 0) {
            std::cerr << "[NovaOS] Command failed: " << cmd << "\n";
        }
    }

public:
    void evaluate(const std::vector<std::shared_ptr<ASTNode>>& program) {
        for (const auto& node : program) {
            if (auto assign = std::dynamic_pointer_cast<AssignmentNode>(node)) {
                std::lock_guard<std::mutex> lock(mem_mutex);
                memory[assign->variable] = assign->value;
            } 
            else if (auto call = std::dynamic_pointer_cast<FunctionCallNode>(node)) {
                if (call->object == "Nova" && call->method == "show") {
                    std::lock_guard<std::mutex> lock(mem_mutex);
                    std::string out = memory.count(call->argument) ? memory[call->argument] : call->argument;
                    std::cout << "[Nova Output]: " << out << "\n";
                }
                else if (call->object == "OS" && call->method == "run") {
                    // Multi-threaded system execution
                    std::thread os_thread(&NovaRuntime::executeSystemCommand, this, call->argument);
                    os_thread.detach(); // Fire and forget for performance
                }
            }
        }
    }

    // Garbage Collection Placeholder (Memory cleanup for long-running processes)
    void runGarbageCollector() {
        std::lock_guard<std::mutex> lock(mem_mutex);
        memory.clear();
        std::cout << "[Nova GC] Memory cleaned up.\n";
    }
};

#endif
