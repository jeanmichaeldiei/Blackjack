//Blackjack
//Plays a simple version of the casino game of blackjack; for 1 - 7 players


#include "game.h"

/*
 * The constructor for a Blackjack game.
 * We must create a player for every player name given to us in the parameter std::vector
 * It must also populate the deck and shuffle the cards
 *
 * Parameters: A reference to a std::vector filled with names of the players
 */
Game::Game(const std::vector<std::string>& names)

{	
	//Initializing deck
	m_Deck.Populate();
	m_Deck.Shuffle();

	//Creating list of Players given names.
	unsigned int i = 0;
	for (i = 0; i < names.size(); i++) {
		m_Players.push_back(Player(names[i]));
	}
}

/*
 * The destructor for the blackjack game.
 */
Game::~Game()
{
	m_Deck.Clear();
	m_House.Clear();
	//delete m_players;

	unsigned int i = 0;
	for (i = 0; i < m_Players.size(); i++) {
		m_Players[i].Clear();
	}
	m_Players.clear();
}

/*
 * All of the logic to play the blackjack game. You will need to follow the rules here.
 *
 * Start by dealing out a card to every player and then dealing a card to the House.
 * For a second time deal a card to every player and then deal a card to the House.
 * Make sure the first card of the House is flipped.
 *
 * Display every player's hand so they know what they have followed by the House's hand
 *
 * Deal additional cards to every player in order
 *
 * Flip the House's first card and print the hand of the House.
 *
 * Deal additional cards to the House. Then Check the win conditions
 *
 * If the house is busted, for every player which has not currently busted, announce
 * to them that they have won
 *
 * If the House did not bust we must check to see who won
 *
 * For every player, if they have not busted, check:
 * 1. If their total is greater than the house's total. Annouce that they've won.
 * 2. If their total is equal to the house's total. Annouce that they have pushed.
 * 3. Otherwise annouce that the player has lost.
 *
 * At the end, Make sure to clear the hands of each Player and the House.
 *
 * Parameters: None
 * Returns: None
 */
void Game::Play()
{
	//Deals two cards to every player and flip the first House card.
	unsigned int i = 0;
	for (i = 0; i < m_Players.size(); i++) {
		m_Deck.Deal(m_Players[i]);
	}
	m_Deck.Deal(m_House);
	m_House.FlipFirstCard();

	for (i = 0; i < m_Players.size(); i++) {
		m_Deck.Deal(m_Players[i]);
	}
	m_Deck.Deal(m_House);


	//Display the hand to every player.
	for (i = 0; i < m_Players.size(); i++) {
		std::cout << m_Players[i];
	}
	std::cout << m_House;


	//Dealing additional cards to players.
	for (i = 0; i < m_Players.size(); i++) {
		m_Deck.AdditionalCards(m_Players[i]);
	}


	//House's turn to recieve cards	
	m_House.FlipFirstCard();
	std::cout << m_House;
	m_Deck.AdditionalCards(m_House);

	//Win conditions.
	if(m_House.IsBusted()) {
		for (i = 0; i < m_Players.size(); i++) {
			if(!m_Players[i].IsBusted()) {
				m_Players[i].Win();
			}
		}
	}

	else {
		for (i = 0; i < m_Players.size(); i++) {
			if(m_House.GetTotal() > m_Players[i].GetTotal()) {
				m_Players[i].Lose();
			}

			if(m_House.GetTotal() == m_Players[i].GetTotal() && m_Players[i].GetTotal() <= 21) {
				m_Players[i].Push();
			}

			if(m_House.GetTotal() < m_Players[i].GetTotal() && m_Players[i].GetTotal() <= 21) {
				m_Players[i].Win();
			}

		}
	}

	//Clear house and player hands.
	for (i = 0; i < m_Players.size(); i++) {
		m_Players[i].Clear();
	}
	m_House.Clear();
}
