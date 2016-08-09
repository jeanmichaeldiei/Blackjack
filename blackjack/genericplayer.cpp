#include "genericplayer.h"

/*
 * Constructor for a GenericPlayer.
 *
 * Parameters: A reference to a std::string
 */
GenericPlayer::GenericPlayer(const std::string& name)
{
	m_Name = name;
}

/*
 * Destructor for a Generic Player
 */
GenericPlayer::~GenericPlayer()  
{}

/*
 * A quick function to check if a player's hand is greater than 21
 *
 * Parameters: None
 * Returns:
 *      true if the Generic Player's hand value is greater than 21
 *      false if the Generic Player's hand value is less than 21
 */
bool GenericPlayer::IsBusted() const
{
	if (GetTotal() > 21) {
		return true;
	}
    return false;
}

/*
 * Print a message telling the player they have busted:
 * "<name> busts.\n"
 *
 * Parameters: None
 * Returns: None
 */
void GenericPlayer::Bust() const
{
	std::cout << m_Name << " busts.\n\n";
}


/*
 * Overloads << operator so a GenericPlayer object can be sent to std::cout
 * If the hand is empty simply print "<empty>"
 * Otherwise print it out in the format
 * "<name>:\tCard1\t...CardN\t"
 *
 * If the total value of the player's cards is not 0, print the total in the form:
 * "(<total_value>)"
 *
 * Parameters:
 *      lefthand side: a reference to an output stream
 *      righthand side: a reference to a generic player to print out
 *
 * Returns:
 *      a reference to an output stream
 */
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
	int total = aGenericPlayer.GetTotal();
    	if(total == 0) {
		os << "<empty>\n";
		return os;
	}
	else {
		os << aGenericPlayer.m_Name << ":\t";
		std::vector<Card*>::const_iterator start = aGenericPlayer.m_Cards.begin();
		std::vector<Card*>::const_iterator end = aGenericPlayer.m_Cards.end();
		while(start != end) {
			os << (**start);
			start++;
		}

	}
	os << "Total: " << total << "\n";
	return os;
}
