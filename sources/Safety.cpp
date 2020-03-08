#include <iostream>
#include "../includes/Card.h"
#include "../includes/Safety.h"

//Create a safety card

Safety::Safety() : Card("", SAFETY) {
	m_protection = PUNCTURE_PROOF;
}

//Create a safety card from another safety card

Safety::Safety(const Safety& safety) : Card(safety) {
	m_protection = safety.m_protection;
}

//Create a safety card from card's parameters

Safety::Safety(const std::string& name) : Card(name, SAFETY) {
	m_protection = PUNCTURE_PROOF;
}

//Create a safety card from safety card's parameters

Safety::Safety(const std::string& name, const Protection& protection) : Card(name, SAFETY) {
	m_protection = protection;
}

//Return the type of protection of the card

Protection Safety::getProtection() {
	return m_protection;
}

//Print details about the safety card

void Safety::details() {
	Card::details();
	std::cout << "\t[" << m_protection << "]" << std::endl;
}