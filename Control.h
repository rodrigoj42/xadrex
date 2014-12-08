#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

class Control
{
friend class ControlManager;
public:
    int x, y;
    int width, height;

protected:
    virtual void onMouseEnter();
    virtual void onMouseLeave();
    virtual void onMouseDown();
    virtual void onMouseUp();
    virtual void onClick(int x, int y);
    bool mouseDown;
    bool mouseOver;
};

#endif // CONTROL_H_INCLUDED
