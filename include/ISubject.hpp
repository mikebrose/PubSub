#ifndef _ISUBJECT_
#define _ISUBJECT_
#include <forward_list>
#include <map>
#include "IObserver.hpp"

// An abstract interface for a subject than can publish to different categories of subscribers
class ISubject {
public:

virtual ~ISubject() {};

virtual void AddObserver(int message_type, IObserver* observer);

virtual void RemoveObserver(int message_type, IObserver* observer);

virtual void NotifyAll();

virtual void Notify(int message_type);


private:
std::map<int, std::forward_list<IObserver*>> mObserver_map;
};

#endif