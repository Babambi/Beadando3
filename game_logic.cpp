#include "game_logic.hpp"

GameLogic::GameLogic(int size)
    : board_size(size), board(size, std::vector<int>(size, 0)), game_over(false), click_count(0) {}

bool GameLogic::check_winner() {
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
                    winning_line = {j, i, j + 4, i};
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
                    winning_line = {j, i, j, i + 4};
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
                    winning_line = {j, i, j + 4, i + 4};
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
                    winning_line = {j, i, j - 4, i + 4};
                    return true;
                }
            }
        }
    }

    return false;
}

bool GameLogic::is_board_full() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool GameLogic::is_game_over() const {
    return game_over;
}

int GameLogic::get_cell(int x, int y) const {
    return board[y][x];
}


void GameLogic::make_move(int x, int y) {
    if (board[y][x] == 0 && !game_over) {
        if (click_count % 2 == 0) {
            board[y][x] = 1;
        } else {
            board[y][x] = 2;
        }
        click_count++;

        if (check_winner() || is_board_full()) {
            game_over = true;
        }
    }
}


void GameLogic::reset() {
    board.resize(board_size, std::vector<int>(board_size, 0));
    game_over = false;
    click_count = 0;
}

int GameLogic::get_board_size() const {
    return board_size;
}

Line GameLogic::get_winning_line() const {
    return winning_line;
}
