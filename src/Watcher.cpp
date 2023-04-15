#include "Watcher.hpp"
#include <iostream>

Watcher::Watcher(const std::string& name) 
    : mName(name) {}

void Watcher::OnNotify(){
    std::cout << "Hello from: " << mName << std::endl;
}