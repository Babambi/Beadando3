#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "widget.hpp"
#include "graphics.hpp"

class Board : public Widget
{
protected:
    std::vector<std::vector<int>> board;
    int cell_size;
    int board_size;
    bool _checked;
    bool game_over;

public:
    Board(int x, int y, int size, int cell_size);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool check_winner();
    virtual bool is_board_full();
};

#endif // BOARD_HPP_INCLUDED
