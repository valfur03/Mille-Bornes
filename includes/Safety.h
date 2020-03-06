#ifndef SAFETY_H_INCLUDED
#define SAFETY_H_INCLUDED

#include <string>
#include "Card.h"

class Safety : public Card {
public:
	Safety();
	Safety(const Safety& safety);
	Safety(const std::string& name);
	Safety(const std::string& name, const Protection& protection);

	void details(); //Print details about the card

private:
	Protection m_protection; //Type of protection of the card (cf. Card.h)
};

#endif