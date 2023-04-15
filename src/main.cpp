#include <iostream>
#include "Watcher.hpp"
#include "Subject.hpp"

int main(int, char**) {
    Watcher physicswatcher1("PhysicsWatcher1");
    Watcher physicswatcher2("PhysicsWatcher2");
    Watcher physicswatcher3("PhysicsWatcher3");

    Watcher soundwatcher1("SoundWatcher1");
    Watcher soundwatcher2("SoundWatcher2");
    Watcher soundwatcher3("SoundWatcher3");

    Watcher logwatcher1("LogWatcher1");
    Watcher logwatcher2("LogWatcher2");
    Watcher logwatcher3("LogWatcher3");

    Subject subject;
    // Add observers interested in physics events
    subject.AddObserver(Subject::HANDLEPHYSICS, &physicswatcher1);
    subject.AddObserver(Subject::HANDLEPHYSICS, &physicswatcher2);
    subject.AddObserver(Subject::HANDLEPHYSICS, &physicswatcher3);

    // Add observers interested in sound events
    subject.AddObserver(Subject::PLAYSOUND, &soundwatcher1);
    subject.AddObserver(Subject::PLAYSOUND, &soundwatcher2);
    subject.AddObserver(Subject::PLAYSOUND, &soundwatcher3);

    // Add observers interested in logging events
    subject.AddObserver(Subject::LOG, &logwatcher1);
    subject.AddObserver(Subject::LOG, &logwatcher2);
    subject.AddObserver(Subject::LOG, &logwatcher3);

    std::cout << "=====Notify All======" << std::endl;
    subject.NotifyAll();
    std::cout << " =====Notify Physics Observers===== " << std::endl;
    subject.Notify(Subject::HANDLEPHYSICS);
    std::cout << " =====Notify Sound Observers===== " << std::endl;
    subject.Notify(Subject::PLAYSOUND);
    std::cout << " =====Notify Log Observers===== " << std::endl;
    subject.Notify(Subject::LOG);

    std::cout << "=====Removing Sound observer 2=====" << std::endl;
    subject.RemoveObserver(Subject::PLAYSOUND ,&soundwatcher2);
    std::cout << "=====Notify Sound Observers===== " << std::endl;
    subject.Notify(Subject::PLAYSOUND);

    std::cout << " =====Notify All=====" << std::endl;
    subject.NotifyAll();
    
    return 0;
}
