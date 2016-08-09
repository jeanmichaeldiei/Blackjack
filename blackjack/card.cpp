#include "card.h"

/*
 *  The constructor for the Card class.
 *  Fills the members of the Card based on the parameters
 *
 *  parameters:
 *      r - a value from the enumeration rank
 *      s - a suit from the enumeration suit
 *      ifu - a boolean tell us whether the card is face up or not
 */

Card::Card(rank r, suit s, bool ifu)
{
	m_Rank = r;
	m_Suit = s;
	m_IsFaceUp = ifu;
} 

/*
 * Return the blackjack numerical value of a card
 *
 * Parameters: None
 * Return:
 *      If the card is face down, return 0
 *      Otherwise follow this scheme:
 *      For an Ace, return 1
 *      For 2-9 return, return their value
 *      For 10, Jack, Queen, King return 10
 *
 */
int Card::GetValue() const
{
	if(!m_IsFaceUp) {
		return 0;
	}
	if (m_Rank == JACK || m_Rank == QUEEN || m_Rank == KING) {
		return 10;
	}
    return (signed int)m_Rank;
}

/*
 *  Flip the boolean.
 *  If the card was previously face down, now it is face up
 *  If the card was previously face up, now it is face down
 *
 *  Parameters: None
 *  Returns: None
 */
void Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
}


/*
 * Overloads << operator so Card object can be sent to cout
 * If a card is face down, print "XX"
 * Otherwise print the rank followed by the suit
 *
 * Parameters:
 *      lefthand side: a reference to an output stream
 *      righthand side: a reference to the card we wish to print
 *
 * Returns:
 *      a reference to an output stream
 */
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	if(aCard.m_IsFaceUp) {
		std::string suitName;
		std::string rankName;
		switch (aCard.m_Rank) {
			case Card::ACE: {
					rankName = "ACE";	
					break;
				}
	
			case Card::JACK: {
					rankName = "JACK";
					break;
				}
			case Card::QUEEN: {
					rankName = "QUEEN";
					break;
				}
			case Card::KING: {
					rankName = "KING";
					break;
				}
			default: {
					 rankName = std::to_string(aCard.GetValue());
				 }
		}



		switch (aCard.m_Suit) {
			case Card::CLUBS: {
					suitName = "CLUBS";	
					break;
				}
			case Card::DIAMONDS: {
					suitName = "DIAMONDS"; 
					break;
				}
			case Card::HEARTS: {
					suitName = "HEARTS";
					break;
				}
			case Card::SPADES: {
					suitName = "SPADES";
					break;
				}
		}
				
		os << rankName << " of " << suitName << "  |  ";
	}
	else {
		os<< "XX\t";
	}
    return os;
}
