#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include "ISubject.hpp"

// This particular subject offers 3 categories of events to subsribe to
class Subject : public ISubject {
public:
    enum MessageTypes {
        PLAYSOUND,
        HANDLEPHYSICS,
        LOG
    };

// No significant difference from base class
};


#endif