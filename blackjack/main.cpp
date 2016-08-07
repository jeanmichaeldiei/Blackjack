#include "main.h"

/*
 * This is your main title screen for your game
 *
 * Start by setting up the seed for your random number generator
 * Print a message to your players that they are playing your game!
 * Find out how many players wish to play (between [1, 7])
 *
 * Use the standard input to find out their names then create a blackjack game
 * Create some loop logic such that we can play the game over and over again
 * so long as the players say they wish to play again.
 */
int main()
{
	std::cout << "Welcome to Blackjack!\n";
	int numPlayers = 0;
	do {
		std::cout << "How many players are wishing to play? (up to 7 players)\n";
		std::cin >> numPlayers;
	}while(numPlayers < 1 && numPlayers >7);
	
	std::vector<std::string> names;
	
	int i = 0;
	std::string aName;

	for (i = 0; i < numPlayers; i++) {
		std::cout << "Player " << i + 1<< " name: ";
		std::cin >> aName;
		names.push_back(aName);
	}
	char ans = 'y';
	while(ans == 'y' || ans == 'Y') {
		Game game (names);
		game.Play();
		std::cout<< "Do you wish to play again?(y/n)\n";
		std::cin >> ans;
	}
	std::cout << "Hope you had fun! Goodbye.\n";
	return 0;
}
