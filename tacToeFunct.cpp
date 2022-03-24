#include <iostream>
#include <vector>
#include <cstdlib>
//variables are global in order to be interacted with at all times.

//graphics for tictactoe game
std::string line1 = " 1  | 2  | 3  \n";
std::string line2 = " 4  | 5  | 6  \n";
std::string line3 = " 7  | 8  | 9  \n\n";
std::string divider = "____|____|____\n";

//global placeholders to be interacted with
char playerChar;
int first = 0; //initialized as 0, just to have default value
int moves = 0; //allows control of maximum number of moves.
bool win = false;

//basic commands for general purpose
char get_Player(){
    return playerChar;
}

int get_Moves(){
    return moves;
}

bool get_Win(){
    return win;
}

//structure for game

//display for tictactoe
void get_Display(){ 
    std::cout << line1;
    std::cout << divider;
    std::cout << line2;
    std::cout << divider;
    std::cout << line3;
}

//gets display inputs, and changes the board.
void get_Display_Input(int move, char playerChar){
    switch(move){
        case 1: //uses line 1
           line1.at(1) = playerChar;
           break;
        case 2:
             line1.at(6) = playerChar;
            break;
        case 3:
            line1.at(11) = playerChar;
            break;
        case 4: //uses line 2
            line2.at(1) = playerChar;
            break;
        case 5:
            line2.at(6) = playerChar;
            break;
        case 6:
            line2.at(11) = playerChar;
            break;
        case 7: //uses line 3
            line3.at(1) = playerChar;
            break;
        case 8:
            line3.at(6) = playerChar;
            break;
        case 9:
            line3.at(11) = playerChar;
            break;
    }

}

//player switcher
void switch_Player(){
    if(first == 0){
        playerChar = 'O';
        first = 1;
    }
    else{
        playerChar = 'X';
        first = 0;
    }
}

//initializes who goes first
void initialPlayer(){
    srand(time(NULL));
    first = std::rand() % 2;
    if (first == 0){
        playerChar = 'X';
    }
    else if (first == 1){
        playerChar = 'O';
    }
}

//does what it called, 8 different win conditions.
void check_Win(){
    if ((playerChar == line1.at(1)) && (playerChar == line1.at(6)) && (playerChar == line1.at(11))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
    else if ((playerChar == line2.at(1)) && (playerChar == line2.at(6)) && (playerChar == line2.at(11))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
     else if ((playerChar == line3.at(1)) && (playerChar == line3.at(6)) && (playerChar == line3.at(11))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }   
    else if ((playerChar == line1.at(1)) && (playerChar == line2.at(6)) && (playerChar == line3.at(11))){
        std::cout << playerChar << " has won! \n"; 
        win = true;
    }
    else if ((playerChar == line1.at(6)) && (playerChar == line2.at(6)) && (playerChar == line3.at(6))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
    else if ((playerChar == line1.at(1)) && (playerChar == line2.at(1)) && (playerChar == line3.at(1))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
    else if ((playerChar == line1.at(11)) && (playerChar == line2.at(11)) && (playerChar == line3.at(11))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
    else if ((playerChar == line1.at(11)) && (playerChar == line2.at(6)) && (playerChar == line3.at(1))){
        std::cout << playerChar << " has won! \n";
        win = true;
    }
    else{
        win = false;
    }
    moves++; //allows for while loops to not be stuck
}