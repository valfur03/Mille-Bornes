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