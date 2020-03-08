#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>
#include <vector>

enum Protection {
	RIGHT_WAY,
	EXTRA_TANK,
	PUNCTURE_PROOF,
	DRIVING_ACE
};

enum Effect {
	NOTHING,
	STOP,
	SPEED_LIMIT,
	OUT_OF_GAS,
	FLAT_TIRE,
	ACCIDENT
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

	std::string getName(); //Return the name of the card
	Role getRole(); //Return the role of the card
	virtual void details(); //Print details about the card

private:
	std::string m_name; //Name of the card
	Role m_role; //Role of the card
};

#endif