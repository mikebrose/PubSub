#ifndef _IOBSERVER_
#define _IOBSERVER_

// An abstract interface class for Observers
class IObserver {
public:
    virtual ~IObserver() {};
    virtual void OnNotify() = 0;

private:
};


#endif
