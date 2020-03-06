#ifndef HAZARD_H_INCLUDED
#define HAZARD_H_INCLUDED

#include <string>
#include "Card.h"

class Hazard : public Card {
public:
	Hazard();
	Hazard(const Hazard& safety);
	Hazard(const std::string& name);
	Hazard(const std::string& name, const Effect& effect);

	void details(); //Print details about the card

private:
	Effect m_effect; //Type of hazard of the card (cf. Card.h)
};

#endif