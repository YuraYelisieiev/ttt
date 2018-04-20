//
// Created by YuraYeliseev on 4/16/18.
//

#ifndef OOP_TTT_GAME_BOARD_H
#define OOP_TTT_GAME_BOARD_H

#include <vector>
#include <iostream>
#include "game_board.h"

class Game_Board {
public:
    std::vector <std::vector<int>> board = std::vector < std::vector <int> > (3, std::vector<int>(3, 0));

    void printBoard();

    void maake_Turn(int &p1, int &p2, int counter);

    bool win_check(int check)const;

    void clearBoard();

    std::vector<std::vector<int> > & get_board ();

    bool isTie() const;
};
#endif //OOP_TTT_GAME_BOARD_H
