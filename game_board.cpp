//
// Created by YuraYeliseev on 4/16/18.
//
#include "game_board.h"

void Game_Board::printBoard() {
    for (auto &i: board) {
        for (auto &j : i) {
            switch (j) {
                case 0: {
                    std::cout << '-' << '|';
                    break;
                }
                case 1: {
                    std::cout << 'X' << '|';
                    break;
                }
                case 2: {
                    std::cout << 'O' << '|';
                    break;
                }
                default:
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Game_Board::maake_Turn(int &p1, int &p2, int counter) {
    board[p1][p2] = counter;
}

bool Game_Board::win_check(int check)const {
    int rows = 0, columns = 0, diag1 = 0, diag2 = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == check)
                rows++;

            if (board[i][j] == check)
                columns++;

            if (board[j][j] == check)
                diag1++;

            if (board[2 - j][j] == check)
                diag2++;
        }
        if (rows == 3 || columns == 3 || diag1 == 3 || diag2 == 3) {
            return true;
        }
        rows = 0;
        columns = 0;
        diag1 = 0;
        diag2 = 0;

    }
    return false;
}

void Game_Board::clearBoard() {
    for (int i = 0; i < 3; i++) {
        for (auto &j: board) {
            j[i] = 0;
        }
    }
}

 std::vector<std::vector<int> > & Game_Board::get_board () {
    return board;
}


bool Game_Board::isTie() const
{
    for (unsigned int i = 0; i < 3; i++)
    {
        if (board[i][0] == 0 || board[i][1] == 0 || board[i][2] == 0)
            return false;
    }
    return true;
}
