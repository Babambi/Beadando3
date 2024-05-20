#include "application.hpp"

using namespace genv;

Application::Application(int w, int h, int board_size, int cell_size)
    : XX(w), YY(h), board(10, 10, board_size, cell_size) {}

void Application::run() {
   gout.open(XX, YY);

    while (gin >> ev) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            board.handle(ev);
        }

        gout << color(0, 0, 0) << move_to(0, 0) << box(XX, YY);
        board.draw();
        gout << refresh;
    }
}
