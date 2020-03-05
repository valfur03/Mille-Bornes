#ifndef DISTANCE_H_INCLUDED
#define DISTANCE_H_INCLUDED

#include "Card.h"

class Distance : public Card {
public:
	Distance();
	Distance(const Distance& distance);
	Distance(const std::string& name);
	Distance(const std::string& name, const int& distance);

private:
	int m_distance; //Distance of the card
};

#endif