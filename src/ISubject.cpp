#include "ISubject.hpp"
#include "IObserver.hpp"

void ISubject::AddObserver(int message_type, IObserver* observer) {
    auto it = mObserver_map.find(message_type);
    if (it == mObserver_map.end()) {
        // add an empty forward list to the new category if not found
        mObserver_map[message_type] = std::forward_list<IObserver*>();
    }
    mObserver_map[message_type].push_front(observer);
}

void ISubject::RemoveObserver(int message_type, IObserver* observer) {
    // TODO: what happens if entry doesnt exist
    mObserver_map[message_type].remove(observer);
}

void ISubject::NotifyAll() {
    for(std::map<int, std::forward_list<IObserver*>>::iterator it = mObserver_map.begin();
        it != mObserver_map.end(); it++){    
        // will iterate through the observers in the current message type, calling their notify functions
        for (auto observer : mObserver_map[it->first]){
            observer->OnNotify();
        }
    }
}

void ISubject::Notify(int message_type) { 
    for (auto observer : mObserver_map[message_type]){
        observer->OnNotify();
    }
}