#include <iostream>
#include "../includes/Card.h"
#include "../includes/Hazard.h"

//Create a hazard card

Hazard::Hazard() : Card("", HAZARD) {
	m_effect = FLAT_TIRE;
}

//Create a hazard card from another hazard card

Hazard::Hazard(const Hazard& hazard) : Card(hazard) {
	m_effect = hazard.m_effect;
}

//Create a hazard card from card's parameters

Hazard::Hazard(const std::string& name) : Card(name, HAZARD) {
	m_effect = FLAT_TIRE;
}

//Create a hazard card from hazard card's parameters

Hazard::Hazard(const std::string& name, const Effect& effect) : Card(name, HAZARD) {
	m_effect = effect;
}

//Return the hazard card's effect

Effect Hazard::getEffect() {
	return m_effect;
}

//Print details about the hazard card

void Hazard::details() {
	Card::details();
	std::cout << "\t[" << m_effect << "]" << std::endl;
}