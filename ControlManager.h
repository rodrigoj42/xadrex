#ifndef CONTROLMANAGER_H_INCLUDED
#define CONTROLMANAGER_H_INCLUDED

#include <list>
#include "Control.h"

class ControlManager {
public:
    std::list<Control*> controls;
    void onMouseMove(int x, int y);
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
};

#endif // CONTROLMANAGER_H_INCLUDED
