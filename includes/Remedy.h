#ifndef REMEDY_H_INCLUDED
#define REMEDY_H_INCLUDED

#include <string>
#include "Card.h"

class Remedy : public Card {
public:
	Remedy();
	Remedy(const Remedy& remedy);
	Remedy(const std::string& name);
	Remedy(const std::string& name, const Effect& effect);

	Effect getCounterEffect();
	void details(); //Print details about the card

private:
	Effect m_counterEffect; //Type of hazard that the card counter (cf. Card.h)
};

#endif