#ifndef __JACE_EventSystem_
#define __JACE_EventSystem_

#include "../JACE_Common.h"

class EventSystem {
public:
    EventSystem();
    ~EventSystem();

    jBoolean PollQuit();
};

#endif