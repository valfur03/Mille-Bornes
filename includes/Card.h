#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>

enum Protection {
	EXTRA_TANK,
	PUNCTURE_PROOF,
	DRIVING_ACE,
	RIGHT_WAY
};

enum Role {
	SAFETY,
	HAZARD,
	REMEDY,
	DISTANCE
};

class Card {
public:
	Card();
	Card(const Card& card);
	Card(const std::string& name, const Role& role);

	void details(); //Print the details about the card
	std::string getName(); //Return the name of the card

private:
	std::string m_name; //Name of the card
	Role m_role; //Role the card
};

#endif