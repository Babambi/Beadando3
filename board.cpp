#include "board.hpp"
#include <cmath>

using namespace genv;
using namespace std;

Board::Board(int x, int y, int size, int cell_size)
    : Widget(x, y, size * cell_size, size * cell_size),
      cell_size(cell_size),
      board_size(size),
      board(size, std::vector<int>(size, 0)),
      game_over(false)
{

}

void draw_circle(int x, int y, int radius) {
    for (int i = 0; i <= 360; ++i) {
        int px = x + radius * cos(M_PI * i / 180);
        int py = y + radius * sin(M_PI * i / 180);
        gout << move_to(px, py) << color(255,255,255) << dot;
    }
}

bool Board::check_winner() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j <= board_size - 5; j++) {
            int count = 1;
            int player = board[i][j];
            if (player != 0) {
                for (int k = 1; k < 5; k++) {
                    if (board[i][j + k] == player) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 5) {
                    return true;
                }
            }
        }
    }
    for (int j = 0; j < board_size; j++) {
        for (int i = 0; i <= board_size - 5; i++) {
            int count = 1;
            int player = board[i][j];
            if (player != 0) {
                for (int k = 1; k < 5; k++) {
                    if (board[i + k][j] == player) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 5) {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i <= board_size - 5; i++) {
        for (int j = 0; j <= board_size - 5; j++) {
            int count = 1;
            int player = board[i][j];
            if (player != 0) {
                for (int k = 1; k < 5; k++) {
                    if (board[i + k][j + k] == player) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 5) {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i <= board_size - 5; i++) {
        for (int j = 4; j < board_size; j++) {
            int count = 1;
            int player = board[i][j];
            if (player != 0) {
                for (int k = 1; k < 5; k++) {
                    if (board[i + k][j - k] == player) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 5) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::is_board_full() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Board::draw() {
    int square_size = _size_x / board_size;

    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            int square_x = _x + j * square_size;
            int square_y = _y + i * square_size;

            gout << move_to(square_x, square_y) << color(255, 255, 255) << box(square_size, square_size);
            gout << move_to(square_x + 2, square_y + 2) << color(0, 0, 0) << box(square_size - 4, square_size - 4);

            if (board[i][j] == 1) {
                gout << color(255, 255, 255);
                gout << move_to(square_x + 4, square_y + 4) << line(square_size - 8, square_size - 8);
                gout << move_to(square_x + 5, square_y + 4) << line(square_size - 8, square_size - 8);
                gout << move_to(square_x + square_size - 4, square_y + 4) << line(-square_size + 8, square_size - 8);
                gout << move_to(square_x + square_size - 5, square_y + 4) << line(-square_size + 8, square_size - 8);
            }
            if (board[i][j] == 2) {
                draw_circle(square_x + square_size / 2, square_y + square_size / 2, square_size / 3);
            }
        }
    }

    if (game_over) {
        if (check_winner()) {
            for (int i = 0; i < board_size; i++) {
                for (int j = 0; j <= board_size - 5; j++) {
                    int count = 1;
                    int player = board[i][j];
                    if (player != 0) {
                        for (int k = 1; k < 5; k++) {
                            if (board[i][j + k] == player) {
                                count++;
                            } else {
                                break;
                            }
                        }
                        if (count == 5) {
                            int line_x = _x + j * (_size_x / board_size) + square_size / 2;
                            int line_y = _y + i * (_size_y / board_size) + square_size / 2;
                            gout << color(255, 0, 0) << move_to(line_x, line_y) << line_to(line_x + 4 * (_size_x / board_size), line_y);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < board_size; j++) {
                for (int i = 0; i <= board_size - 5; i++) {
                    int count = 1;
                    int player = board[i][j];
                    if (player != 0) {
                        for (int k = 1; k < 5; k++) {
                            if (board[i + k][j] == player) {
                                count++;
                            } else {
                                break;
                            }
                        }
                        if (count == 5) {
                            int line_x = _x + j * (_size_x / board_size) + square_size / 2;
                            int line_y = _y + i * (_size_y / board_size) + square_size / 2;
                            gout << color(255, 0, 0) << move_to(line_x, line_y) << line_to(line_x, line_y + 4 * (_size_y / board_size));
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i <= board_size - 5; i++) {
                for (int j = 0; j <= board_size - 5; j++) {
                    int count = 1;
                    int player = board[i][j];
                    if (player != 0) {
                        for (int k = 1; k < 5; k++) {
                            if (board[i + k][j + k] == player) {
                                count++;
                            } else {
                                break;
                            }
                        }
                        if (count == 5) {
                            int line_x = _x + j * (_size_x / board_size) + square_size / 2;
                            int line_y = _y + i * (_size_y / board_size) + square_size / 2;
                            gout << color(255, 0, 0) << move_to(line_x, line_y) << line_to(line_x + 4 * (_size_x / board_size), line_y + 4 * (_size_y / board_size));
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i <= board_size - 5; ++i) {
                for (int j = 4; j < board_size; ++j) {
                    int count = 1;
                    int player = board[i][j];
                    if (player != 0) {
                        for (int k = 1; k < 5; ++k) {
                            if (board[i + k][j - k] == player) {
                                count++;
                            } else {
                                break;
                            }
                        }
                        if (count == 5) {
                            int line_x = _x + j * (_size_x / board_size) + square_size / 2;
                            int line_y = _y + i * (_size_y / board_size) + square_size / 2;
                            gout << color(255, 0, 0) << move_to(line_x, line_y) << line_to(line_x - 4 * (_size_x / board_size), line_y + 4 * (_size_y / board_size));
                            break;
                        }
                    }
                }
            }
        }
        gout << font("LiberationSans-Regular.ttf",20)<< move_to(_x + _size_x / 2, _y + _size_y / 2) << color(255, 0, 0) << text("Game Over!");
    }
}


void Board::handle(event ev) {
    static int click_count = 0;
    if (!game_over && ev.type == ev_mouse && ev.button == btn_left) {
        int square_x = ev.pos_x / (_size_x / board_size);
        int square_y = ev.pos_y / (_size_y / board_size);
        if (square_x >= 0 && square_x < board_size && square_y >= 0 && square_y < board_size && board[square_y][square_x] == 0) {
            if (click_count % 2 == 0) {
                board[square_y][square_x] = 1;
            } else {
                board[square_y][square_x] = 2;
            }
            click_count++;

            if (check_winner() || is_board_full()) {
                game_over = true;
            }
        }
    }
}
