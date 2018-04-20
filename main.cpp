#include <iostream>
#include <vector>
#include <random>
#include "game_board.h"

class Player {
public:
    std::string name;

    explicit Player(const std::string &new_name) {
        name = new_name;
    }

    Player() = default;

protected:
    explicit Player(const bool &is_pc, const int n_lvl) {
    }

};

class HumanPlayer : Player {
public:
    explicit HumanPlayer(const std::string &new_name) : Player(new_name) {}

    std::pair<int, int> take_turn() {
        int x, y;
        std::cout << "Enter your coordinates: ";
        std::cin >> x >> y;
        return std::make_pair(x, y);
    }
};

class Stupid_AI : public Player {
public:
    std::pair<int, int> take_turn() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 2);
        int x = dist(mt);
        int y = dist(mt);
        return std::make_pair(x, y);
    };
};
int counter=0;
class Immortal_AI : public Player {
public:
    int minmax(Game_Board &board, int lvl, bool isMax) {
        if(board.win_check(1)){counter++; return 10/lvl;}
        if(board.win_check(2)){counter++; return -10/lvl;}
        else if(board.isTie()){counter++; return 0/lvl;}
        auto &field = board.get_board();
        int x=0, y=0;
        int value;
        if (isMax) {
            value = std::numeric_limits<int>::min();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (field[i][j] == 0) {
                        field[i][j] = 1;
                        value = std::max(value, minmax(board, lvl + 1000, !isMax) - lvl);
                        field[i][j] = 0;
                    }
                }
            }
            return value;
        } else {
            value = std::numeric_limits<int>::max();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (field[i][j] == 0) {
                        field[i][j] = 2;
                        value = std::min(value, minmax(board, lvl + 1000, !isMax) + lvl);
                        field[i][j] = 0;
                    }
                }
            }
            return value;
        }
    }

    std::pair<int, int> chooseMoove(Game_Board &field) {
        int best = std::numeric_limits<int>::min();
        auto &board = field.get_board();
        int x = -1;
        int y = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    int moove = minmax(field, 0, false);
                    board[i][j] = 0;
                    if (moove > best) {
                        x = i;
                        y = j;
                        best = moove;
                    }
                }
            }
        }
        return std::make_pair(x, y);
    }
};

class Game {
public:
    void play() {
        char y_n;
        HumanPlayer p1("Player #1");
        Game_Board field;
        Immortal_AI pc;
        int x, y, x1, y1;
        int mooves = 0;
        int lvl = 0;
        while (true) {
            std::cout << "Enter your parameters(example ' 2 1 ')" << std::endl;
            std::tie(x1, y1) = p1.take_turn();
            if (0 > x1 || x1 >= 3 || 0 > y1 || y1 >= 3) {
                std::cout << "you entered wrong params" << std::endl;
                break;
            }
            if (field.board[x1][y1] == 0) {
                field.maake_Turn(x1, y1, 1);
            }
            field.printBoard();
            lvl++;
            std::tie(x, y) = pc.chooseMoove(field);
            field.maake_Turn(x, y, 2);
            field.printBoard();
            if (field.win_check(1)) {
                std::cout << "Player wins";
                return;
            } else if (field.win_check(2)) {
                std::cout << "PC wins";
                return;
            }
            mooves += 1;
            if (mooves == 9) {
                std::cout << "its draw";
                return;
            }
        }
    }
};

int main() {
    Game g;
    g.play();
    return 0;
}