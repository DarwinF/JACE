#ifndef __JACE_EventSystem_
#define __JACE_EventSystem_

#include "../JACE_Common.h"
#include "../JACE_Graphics.h"

class EventSystem {
public:
    EventSystem();
    ~EventSystem();

    Boolean PollQuit();
};

#endif