#include "hand.h"

/*
 * Constructor for the Hand class
 */
Hand::Hand()
{}

/*
 * Destructor for the Hand class.
 *
 * REMEMBER every class that inherits from Hand will call this method
 */
Hand::~Hand()  
{
	Clear();
}

/*
 * Add a card to your hand
 *
 * Parameters: A card pointer for a card we wish to add to our hand
 * Returns: None
 */
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
 
/*
 * Cleans up all of the cards in our Hand.
 * This function must also delete all of the memory taken up by the cards
 *
 * Parameters: None
 * Returns: None
 */
void Hand::Clear()
{
	std::vector<Card*>::const_iterator start = m_Cards.begin();
	std::vector<Card*>::const_iterator end = m_Cards.end();

	while(start != end) {
		delete *start;
		start++;
	}
	m_Cards.clear();
}

/*
 * Get the total points for our hand. Add up the points for each card
 * 
 * Parameters: none
 * Returns:
 *      If the hand is empty, return 0
 *      If one of the cards in the hand is face down, return 0
 *      Otherwise return the total value of all the cards in the hand.
 *      If one of the cards is an ACE and the total of the hand would be 21 or lower,
 *      treat the Ace as value 11 instead of 1.
 */
int Hand::GetTotal() const
{
	if (m_Cards.size() == 0) {
		return 0;
	}
	std::vector<Card*>::const_iterator start = m_Cards.begin();
	std::vector<Card*>::const_iterator end = m_Cards.end();

	//Finding total while also checking if card is face down.
	//What to do if there are more than one Ace?
	int aceCount = 0;
	int total = 0;
	while(start != end) {
		if((*start)->GetValue() == 0) {
			return 0;
		}
		total += (*start)->GetValue();
		if((*start)->GetValue() == 1) {
			aceCount++;
		}
		start++;
	}

	while (aceCount > 0) {
		if (total + 10 <= 21) {
			total += 10;
		}
		aceCount--;	
	}
	return total;

}
