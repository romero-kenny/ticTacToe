#include <iostream>
#include "tacToeFunct.hpp"

int main(){

    //initialize starting variables
    int userInput = -1;
    
    //initial game start
    std::cout << "TIC - TAC - TOE\n";
    std::cout << "GAME START!\n";
    get_Display();    //gets display
    initialPlayer();

    //prompts and gets user input
    while (get_Moves() < 9 && get_Win() == false ){
        std::cout << get_Player() << " TURN!\n";
        std::cout << "Please insert where you'd like to place your piece.\n";
        std::cin >> userInput;

        //puts user move to display
        get_Display_Input(userInput, get_Player());
        get_Display();

        //checks if someone has won and switches players.
        check_Win();
        switch_Player();
    }

    //Statements to show after game ends
    if (get_Win() == true){
        std::cout << "GAME OVER!\n";
    }
    else{
        std::cout << "DRAW!\n";
        std::cout<< "GAME OVER!\n";
    }


}    