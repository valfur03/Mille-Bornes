#include <iostream>
#include <string>
#include "../includes/Card.h"

//Create a card

Card::Card() {
	m_name = "Increvable";
	m_role = SAFETY;
}

//Create a card from another card

Card::Card(const Card& card) {
	m_name = card.m_name;
	m_role = card.m_role;
}

//Create a card from parameters

Card::Card(const std::string& name, const Role& role) {
	m_name = name;
	m_role = role;
}

void Card::details() {
	std::cout << m_name << " [" << m_role << "]" << std::endl;
}

std::string Card::getName() {
	return m_name;
}