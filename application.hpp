#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "board.hpp"
#include "graphics.hpp"

class Application {
private:
    Board board;
    genv::event ev;
    const int XX;
    const int YY;

public:
    Application(int w, int h, int board_size, int cell_size);
    void run();
};

#endif // APPLICATION_HPP_INCLUDED
