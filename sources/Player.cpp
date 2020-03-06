#include <iostream>
#include <vector>
#include "../includes/Player.h"
#include "../includes/Card.h"

//Create a player

Player::Player() {
	m_playerName = "Valtou";
	m_nbCards = 6;
	m_hand.push_back(Card());
	m_hand.push_back(Card());
	m_hand.push_back(Card());
	m_hand.push_back(Card());
	m_hand.push_back(Card());
	m_hand.push_back(Card());
	m_travelledDistance = 0;
}

void Player::dispHand() {
	for (int i = 0; i < m_nbCards; i++) {
		std::cout << i + 1 << ". " << m_hand[i].getName() << std::endl;
	}
}