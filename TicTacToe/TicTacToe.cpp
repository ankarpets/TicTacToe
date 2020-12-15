// TicTacToe game played with two players. Player 1 playes with X and player 2 playes with O. If it's a tie the game stops.
// Author: ankarpets

#include <iostream>
#include <conio.h>

using namespace std;

char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool if_wins();
bool if_tie();
void game();
void reset();

void board() {  //creating a board
    int num = 0;
    for (int i=0;i<3;i++) {
        for (int j = 0; j < 3; j++) {            
            cout << "[" << square[num] << "]" << "\t"; 
            num++;
        }
        cout << endl;
    }
}

int main()
{
    char r;

    cout << "Tic Tac Toe Game" << endl;
label_game:

    game();
    cout << "Press R to reset" << endl;
    cin >> r;
    if (tolower(r) == 'r') {
        reset();
        goto label_game;
    }

    _getch();
    return 0;
}

bool if_wins() {    //checking if it's a win situation
    if (square[0] == square[1] && square[0] == square[2])
        return 1;
    if (square[3] == square[4] && square[3] == square[5])
        return 1;
    if (square[6] == square[7] && square[6] == square[8])
        return 1;

    if (square[0] == square[3] && square[0] == square[6])
        return 1;
    if (square[1] == square[4] && square[1] == square[7])
        return 1;
    if (square[2] == square[5] && square[2] == square[8])
        return 1;

    if (square[0] == square[4] && square[0] == square[8])
        return 1;
    if (square[2] == square[4] && square[2] == square[6])
        return 1;
   

    return 0;
}

void game() {   
    board();
    int cell;
    do {
    label1:
            cout << "Player 1 (Plays with X). Enter the number of the cell: ";
            cin >> cell;           
            if (int(square[cell - 1])-48 != cell) { //checking if the cell is occupied
                cout <<"Not possible move" << endl;
                goto label1;
            }  
            square[cell - 1] = 'X';
            board();       
        if (if_wins()) { 
            cout << "Congratilations! Player 1 has won!" << endl;
            break; 
        }

        if (if_tie()) { //checking if it's a tie
            break;
        }

    label2:
        cout << "Player 2 (Plays with O). Enter the number of the cell: ";
        cin >> cell;
        if (int(square[cell - 1]) - 48 != cell) { //checking if the cell is occupied
            cout << "Not possible move" << endl; 
            goto label2;
        }
            square[cell - 1] = 'O';
            board();
        if (if_wins()) {
            cout << "Congratilations! Player 2 has won!" << endl;
            break;
        }

       
    } while (true);
    
}

bool if_tie() {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        if (square[i] == 'O' || square[i] == 'X')
            count++;
    }
    
    if (count == 9) {
        cout << "It's a tie!" << endl;
        return 1;
    }

    return 0;
}

void reset() {  //reset the game by rewriting the square with initial numbers
    
    square[0] = '1';
    square[1] = '2';
    square[2] = '3';
    square[3] = '4';
    square[4] = '5';
    square[5] = '6';
    square[6] = '7';
    square[7] = '8';
    square[8] = '9';

}
