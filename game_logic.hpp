#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <vector>

struct Line {
    int start_x, start_y;
    int end_x, end_y;
};

class GameLogic {
private:
    int board_size;
    std::vector<std::vector<int>> board;
    bool game_over;
    int click_count;
    Line winning_line;

public:
    GameLogic(int size);
    bool check_winner();
    bool is_board_full();
    bool is_game_over() const;
    int get_cell(int x, int y) const;
    void make_move(int x, int y);
    void reset();
    int get_board_size() const;
    Line get_winning_line() const;
};

#endif // GAME_LOGIC_HPP
