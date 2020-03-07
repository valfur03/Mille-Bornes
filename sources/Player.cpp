#include <iostream>
#include <vector>
#include "../includes/Player.h"
#include "../includes/Card.h"

//Create a player

Player::Player() {
	m_playerName = "No name";
	m_nbCards = 0;
	m_hand;
	m_protection;
	m_travelledDistance = 0;
	m_speedLimit = false;
	m_effect = NOTHING;
}

Player::Player(const Player& player) {
	m_playerName = player.m_playerName;
	m_nbCards = player.m_nbCards;
	m_travelledDistance = player.m_travelledDistance;
	m_hand = player.m_hand;
	m_protection = player.m_protection;
	m_speedLimit = player.m_speedLimit;
	m_effect = player.m_effect;
}

Player::Player(const std::string& name) {
	m_playerName = name;
	m_nbCards = 0;
	m_hand;
	m_protection;
	m_travelledDistance = 0;
	m_speedLimit = false;
	m_effect = NOTHING;
}

//Display player's card one by one

void Player::dispHand() {
	for (int i = 0; i < m_nbCards; i++) {
		std::cout << i + 1 << ". " << m_hand[i]->getName() << std::endl;
	}
}