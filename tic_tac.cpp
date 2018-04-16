#include <iostream>

using namespace std;

void map_show(int board[3][3]){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                switch (board[j][i]){
                    case 0: {
                        cout << '-'<< '|';
                        break;
                    }
                    case 1:{
                        cout << 'X' << '|';
                        break;
                        }
                    case 2:{
                        cout << 'O'<< '|';
                             break;
                    }
                    default:break;
                }
            }
            cout << endl;
        }
}

bool win_check(int board[3][3], int check){
    int rows=0, columns=0, diag1=0, diag2=0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[j][i] == check)
                rows++;

            if (board[i][j] == check)
                columns++;

            if (board[j][j] == check)
                diag1++;

            if (board[2-j][j] == check)
                diag2++;
        }
        if(rows == 3 || columns == 3 || diag1 == 3 || diag2 == 3){
            return true;
        }
        rows=0;
        columns=0;
        diag1=0;
        diag2=0;

    }
    return false;
}
int main() {
    int board[3][3] = {0};
    int x, y, moves = 0;
    int counter = 0;
    while (true) {
        label:
        cout << "Enter your coordinates: ";
        cin >> x >> y;
        counter = ((counter + 1) % 2) + 1;
        if(0 > x || x >= 3 || 0 > y || y >= 3){
            cout<< "you entered wrong params"<< endl;
            goto label;
        }
        if (board[y][x] != 1 && board[y][x] != 2){
            board[y][x] = counter;
        }
        map_show(board);
        if (win_check(board, counter)){
            cout << "Player wins";
            break;
        }
        moves += 1;
        if (moves == 9){
            cout << "Its a draw" << endl;
            break;
        }
        counter += 1;
    }
    return 0;
}
