#ifndef DISTANCE_H_INCLUDED
#define DISTANCE_H_INCLUDED

#include "Card.h"

class Distance : public Card {
public:
	Distance();
	Distance(const Distance& distance);
	Distance(const std::string& name);
	Distance(const std::string& name, const int& distance);

	int getDistance();
	void details(); //Print details about the card

private:
	int m_distance; //Distance of the card
};

#endif