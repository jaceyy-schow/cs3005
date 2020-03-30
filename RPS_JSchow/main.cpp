#include "rps.h"


int main( ) {

	initializeRandomNumbers( );
	bool play = true;
	int WIN = 0;
	int LOSE = 0;
	int TIES = 0;

	while (play) {
		int computer = getRandomPlayerChoice( );
		int player = getUserPlayerChoice(std::cin, std::cout);
		if ( player != 0 ) {
			int win = determineWinner(player, computer);
			if ( win == USER ) {
				WIN += 1;
			} 
			else if ( win == RANDOM ) {
				LOSE += 1;
			}
			else {
				TIES += 1;
			}
		displayMatchResults(std::cout, player, computer, win);
		displayStatistics(std::cout, WIN, LOSE, TIES);
		play = askUserIfGameShouldContinue(std::cin, std::cout );
		} 
		else {
			std::cout << "Key unrecognized. " << std::endl;
			std::cout << " " << std::endl;
		}
	}
	std::cout << "That was fun! Try again soon. " << std::endl;
	return 0;
}