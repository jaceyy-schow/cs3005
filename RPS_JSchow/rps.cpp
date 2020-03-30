#include "rps.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void initializeRandomNumbers(){
    srand(time(0));
}

int getRandomPlayerChoice(){
    int random_choice = 0;
    random_choice = rand() % 3 + 1;
    return random_choice;
}
int getUserPlayerChoice( std::istream& input_stream, std::ostream& output_stream){
    std::string user_input = "";
    while(user_input != "rock" && user_input != "paper" && user_input != "scissors"){
        output_stream << "Choice? (rock, paper, scissors)" ;
        input_stream >> user_input ;
    }
    if( user_input == "rock"){
        return  1;
    }
    else if (user_input == "paper"){
        return 2;
    }

    else{
        return 3;
    }
    return 0;
}

int determineWinner( int user_choice, int random_choice ){
    if (user_choice == 1 && random_choice == 3 ){
        return 11;
    }
    else if (user_choice == 2 && random_choice == 1){
        return 11;
    }
    else if (user_choice == 3 && random_choice == 2){
        return 11;
    }
    else if (random_choice == 1 && user_choice == 3){
        return 12;
    }
    else if (random_choice == 2 && user_choice == 1){
        return 12;
    }
    else if (random_choice == 3 && user_choice == 2){
        return 12;
    }
    else if (random_choice == user_choice){
        return 13;
    }
    else if (random_choice != 1 || random_choice != 2 || random_choice != 3){
        return 0;
    }
    else if (user_choice != 1 || user_choice != 2 || user_choice != 3){
        return 0;
    }
    else{
        return 0;
    }
}
void displayMatchResults( std::ostream& output_stream, int user_choice, int random_choice, int winner ){
    if (winner == USER){
        if (user_choice == ROCK){
           output_stream << "You chose rock. Computer chose scissors. You win.\n";
        }
        else if (user_choice == PAPER){
            output_stream << "You chose paper. Computer chose rock. You win.\n";
        }
        else if (user_choice == SCISSORS){
            output_stream <<"You chose scissors. Computer chose paper. You win.\n";
        }
    }
    else if (winner == RANDOM){
        if (random_choice == ROCK){
           output_stream <<  "You chose scissors. Computer chose rock. You lose.\n";
        }
        else if (random_choice == PAPER){
            output_stream << "You chose rock. Computer chose paper. You lose.\n";
        }
        else if (random_choice == SCISSORS){
            output_stream << "You chose paper. Computer chose scissors. You lose.\n";
        }
    }
    else if (winner == TIE){
        if (user_choice == ROCK){
            output_stream <<  "You chose rock. Computer chose rock. You tie.\n";
        }
        else if (user_choice == PAPER){
            output_stream << "You chose paper. Computer chose paper. You tie.\n";
        }
        else if (user_choice == SCISSORS){
            output_stream << "You chose scissors. Computer chose scissors. You tie. \n";
        }
    }
}
void displayStatistics( std::ostream& output_stream, int number_user_wins, int number_user_losses, int number_user_ties ){
    output_stream << "Win: " << number_user_wins << "  Lose: " << number_user_losses << "  Tie: " << number_user_ties << "\n";
}
bool askUserIfGameShouldContinue( std::istream& input_stream, std::ostream& output_stream ) {
	output_stream << " Do you want to play again? " << " 'Y' or 'N' ? " << std::endl;
	output_stream << " " << std::endl;
	bool play = true;

	while ( play ) {
		std::string user_input = "";
		input_stream >> user_input;
		if ( user_input[0] == 'y' || user_input[0] == 'Y') {
			output_stream << " " << std::endl;
			play = true;
			return play;
		}
		else{
			output_stream << " " << std::endl;
			play = false;
			return play;
			
		}
	}
	return 0;
}
