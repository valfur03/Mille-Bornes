#include <iostream>
#include "../includes/Distance.h"

//Create a distance card

Distance::Distance() : Card("", DISTANCE) {
	m_distance = 0;
}

//Create a distance card from another distance card

Distance::Distance(const Distance& distance) : Card(distance) {
	m_distance = distance.m_distance;
}

//Create a distance card with a card's parameters

Distance::Distance(const std::string& name) : Card(name, DISTANCE) {
	m_distance = 0;
}

//Create a distance card with a distance card's parameters

Distance::Distance(const std::string& name, const int& distance) : Card(name, DISTANCE) {
	m_distance = distance;
}

//Return the value of the distance's card

int Distance::getDistance() {
	return m_distance;
}

//Print details about the distance card

void Distance::details() {
	Card::details();
	std::cout << "\t" << m_distance << " km" << std::endl;
}