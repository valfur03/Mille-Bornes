#include <iostream>
#include "../includes/Card.h"
#include "../includes/Remedy.h"

//Create a remedy card

Remedy::Remedy() : Card("", REMEDY) {
	m_counterEffect = FLAT_TIRE;
}

//Create a remedy card from another remedy card

Remedy::Remedy(const Remedy& remedy) : Card(remedy) {
	m_counterEffect = remedy.m_counterEffect;
}

//Create a remedy card from card's parameters

Remedy::Remedy(const std::string& name) : Card(name, REMEDY) {
	m_counterEffect = FLAT_TIRE;
}

//Create a remedy card from remedy card's parameters

Remedy::Remedy(const std::string& name, const Effect& effect) : Card(name, REMEDY) {
	m_counterEffect = effect;
}

//

Effect Remedy::getCounterEffect() {
	return m_counterEffect;
}

//Print details about the remedy card

void Remedy::details() {
	Card::details();
	std::cout << "\t[" << m_counterEffect << "]" << std::endl;
}