#include <iostream>
#include "ControlManager.h"

static inline bool isPointOverRect(int x, int y, int w, int h, int point_x, int point_y) {
    return (point_x >= x) && (point_x < w) && (point_y >= y) && (point_y < h);
}

static inline bool isPointOverControl(Control *c, int point_x, int point_y)
{
    return isPointOverRect(c->x, c->y, c->width, c->height, point_x, point_y);
}

void ControlManager::onMouseMove(int x, int y)
{
    std::list<Control*>::const_iterator it;
    for (it = controls.begin(); it != controls.end(); it++)
    {
        Control *c = *it;
        bool oldMouseOver = c->mouseOver;
        c->mouseOver = isPointOverControl(c, x, y);

        if (!oldMouseOver && c->mouseOver) {
            c->onMouseEnter();
        }
        else if (oldMouseOver && !c->mouseOver) {
            c->onMouseLeave();
        }
    }
}

void ControlManager::onMouseDown(int x, int y)
{
    std::list<Control*>::const_iterator it;
    for (it = controls.begin(); it != controls.end(); it++)
    {
        Control *c = *it;
        bool oldMouseDown = c->mouseDown;
        c->mouseDown = isPointOverControl(c, x, y);

        if (!oldMouseDown && c->mouseDown) {
            c->onMouseDown();
        }
    }
}

void ControlManager::onMouseUp(int x, int y)
{
    std::list<Control*>::const_iterator it;
    for (it = controls.begin(); it != controls.end(); it++)
    {
        Control *c = *it;
        if (isPointOverControl(c, x, y)) {
            int rel_x = x - c->x;
            int rel_y = y - c->y;

            bool oldMouseDown = c->mouseDown;
            c->mouseDown = false;

            c->onMouseUp();

            if (oldMouseDown) {
                c->onClick(rel_x, rel_y);
            }
        }
    }
}
