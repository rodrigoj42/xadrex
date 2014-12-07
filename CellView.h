#ifndef CELLVIEW_H_INCLUDED
#define CELLVIEW_H_INCLUDED

class CellView : public Control {
private
    int m_board_x, m_board_y;

public:
    int board_x();
    int board_y();
};

#endif // CELLVIEW_H_INCLUDED
