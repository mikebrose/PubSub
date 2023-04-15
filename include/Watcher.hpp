#ifndef WATCHER_HPP
#define WATCHER_HPP
#include <string>
#include "IObserver.hpp"

// Concrete class of watcher that can subscribe to an observer class
class Watcher : public IObserver {
public:
    Watcher(const std::string& name);
    void OnNotify();

private:
    std::string mName;
};


#endif