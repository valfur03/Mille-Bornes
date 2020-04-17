#include <iostream>
#include <vector>
#include <algorithm>
#include "../includes/Player.h"
#include "../includes/Distance.h"
#include "../includes/Hazard.h"
#include "../includes/Remedy.h"
#include "../includes/Safety.h"

//Create a player

Player::Player() {
	m_name = "No name";
	m_nbCards = 0;
	m_hand;
	m_protection;
	m_travelledDistance = 0;
	m_bornesLimit = 0;
	m_speedLimit = false;
	m_effect = NOTHING;
	m_rePlay = false;
}

Player::Player(const Player& player) {
	m_name = player.m_name;
	m_nbCards = player.m_nbCards;
	m_travelledDistance = player.m_travelledDistance;
	m_bornesLimit = player.m_bornesLimit;
	m_hand = player.m_hand;
	m_protection = player.m_protection;
	m_speedLimit = player.m_speedLimit;
	m_effect = player.m_effect;
	m_rePlay = false;
}

Player::Player(const std::string& name) {
	m_name = name;
	m_nbCards = 0;
	m_hand;
	m_protection;
	m_travelledDistance = 0;
	m_bornesLimit = 0;
	m_speedLimit = false;
	m_effect = NOTHING;
	m_rePlay = false;
}

//Return the player's name

std::string Player::getName() {
	return m_name;
}

//Return the player's protection

std::vector<Protection> Player::getProtection() {
	return m_protection;
}

//Display the details about the player

void Player::details() {
	std::string effects[] = { "Non", "Feu rouge", "Limite de vitesse", "Panne d'essence", "Crevaison", "Accident" };
	std::string protections[] = { "Vehicule prioritaire", "Citerne d'essance", "Increvable", "As du volant" };
	std::cout << "A atteint " << m_travelledDistance << " km" << std::endl;
	std::cout << "Limite de vitesse ? " << m_speedLimit << std::endl;
	std::cout << "Attaque ? " << effects[m_effect] << std::endl;
	std::cout << "Protection(s) : [ ";
	for (int i = 0; i < m_protection.size(); i++) {
		std::cout << protections[m_protection[i]] << " ";
	}
	std::cout << "]" << std::endl;
}

//Display player's card one by one

void Player::dispHand() {
	for (int i = 0; i < m_nbCards; i++) {
		std::cout << i + 1 << ". " << m_hand[i]->getName() << std::endl;
	}
}

//Add a card to the player's hand

bool Player::pickCard(std::vector<Card*>& cardsStack, const std::vector<Card*>& discardStack, const int& nbCards) {
	for (int i = 0; i < nbCards; i++) {
		m_hand.push_back(cardsStack[0]);
		cardsStack.erase(cardsStack.begin());
		m_nbCards++;

		//Check if stack is empty
		if (cardsStack.empty()) {
			if (!discardStack.empty()) {
				cardsStack = discardStack;
			}
			else {
				std::cout << "Il n'y a plus de cartes\n" << std::endl;
				return false;
			}
		}
	}
	return true;
}

//Play the selected card

bool Player::playCard(const int& selectedCard, const std::vector<Player*>& playersList) {
	Card* playedCard = m_hand[selectedCard - 1];
	bool playError = false;
	switch (playedCard->getRole()) {
	case SAFETY:
		m_protection.push_back(dynamic_cast<Safety*>(playedCard)->getProtection());
		if (this->isProtected(m_effect)) {
			m_effect = NOTHING;
			if (this->isProtected(SPEED_LIMIT)) m_speedLimit = false;
		}
		m_rePlay = true;
		break;
	case HAZARD:
		int target;
		for (int i = 0; i < playersList.size(); i++) {
			std::cout << i + 1 << ". " << playersList[i]->getName() << std::endl;
		}
		std::cout << "Contre qui voulez vous-jouer cette carte ? ";
		while (!(std::cin >> target)) {
			std::cout << "Veuillez entrer une valeur valide" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
		if (target < 1 || target > playersList.size()) {
			std::cout << "Ce joueur n'existe pas" << std::endl;
			playError = true;
		}
		else if ((playersList[target-1]->isProtected(dynamic_cast<Hazard*>(playedCard)->getEffect())) || ((playersList[target-1]->isAffected()) && dynamic_cast<Hazard*>(playedCard)->getEffect() != SPEED_LIMIT) || (playersList[target-1]->getName() == m_name)) {
			std::cout << "Ce joueur ne peut pas etre attaque" << std::endl;
			playError = true;
		}
		if (!playError) playersList[target - 1]->getAttack(dynamic_cast<Hazard*>(playedCard)->getEffect());
		break;
	case REMEDY:
		switch (m_effect) {
		case NOTHING:
			if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car vous n'etes pas attaque" << std::endl;
				playError = true;
			}
			break;
		case STOP:
			if (dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == STOP) {
				m_effect = NOTHING;
			}
			else if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car elle ne corrige pas votre attaque" << std::endl;
				playError = true;
			}
			break;
		case SPEED_LIMIT:
			if (dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_effect = NOTHING;
			}
			else if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car elle ne corrige pas votre attaque" << std::endl;
				playError = true;
			}
			break;
		case OUT_OF_GAS:
			if (dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == OUT_OF_GAS) {
				m_effect = NOTHING;
			}
			else if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car elle ne corrige pas votre attaque" << std::endl;
				playError = true;
			}
			break;
		case FLAT_TIRE:
			if (dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == FLAT_TIRE) {
				m_effect = NOTHING;
			}
			else if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car elle ne corrige pas votre attaque" << std::endl;
				playError = true;
			}
			break;
		case ACCIDENT:
			if (dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == ACCIDENT) {
				m_effect = NOTHING;
			}
			else if (m_speedLimit && dynamic_cast<Remedy*>(playedCard)->getCounterEffect() == SPEED_LIMIT) {
				m_speedLimit = false;
			}
			else {
				std::cout << "Vous ne pouvez pas utiliser cette carte car elle ne corrige pas votre attaque" << std::endl;
				playError = true;
			}
			break;
		}
		break;
	case DISTANCE:
		if (m_travelledDistance + dynamic_cast<Distance*>(playedCard)->getDistance() > 1000) {
			std::cout << "Vous ne pouvez pas depasser 1000 bornes" << std::endl;
			playError = true;
		}
		else if (m_bornesLimit == 2 && dynamic_cast<Distance*>(playedCard)->getDistance() == 200) {
			std::cout << "Vous ne pouvez pas jouer plus de deux cartes 200 bornes" << std::endl;
			playError = true;
		}
		else if (m_effect != NOTHING) {
			std::cout << "Vous etes attaque, vous ne pouvez toujours pas avancer !" << std::endl;
			playError = true;
		}
		else if (m_speedLimit && dynamic_cast<Distance*>(playedCard)->getDistance() > 50) {
			std::cout << "Vous avez une limite de vitesse, vous ne pouvez pas autant avancer !" << std::endl;
			playError = true;
		}
		else {
			m_travelledDistance += dynamic_cast<Distance*>(playedCard)->getDistance();
			if (dynamic_cast<Distance*>(playedCard)->getDistance() == 200) m_bornesLimit++;
		}
		break;
	}
	if (playError) return false;
	m_hand.erase(m_hand.begin() + (selectedCard - 1));
	m_nbCards--;
	return true;
}

//Discard a card :)


void Player::disCard(const int& selectedCard, std::vector<Card*>& discardCardsStack) {
	discardCardsStack.push_back(m_hand[selectedCard - 1]);
	m_hand.erase(m_hand.begin() + (selectedCard - 1));
	m_nbCards--;
}

//Get attacked by a player

void Player::getAttack(const Effect& effect) {
	if (effect != SPEED_LIMIT) {
		m_effect = effect;
	}
	else m_speedLimit = true;
}

//Return true if the player is protected against some hazard cards

bool Player::isProtected(const Effect& effect) {
	switch(effect) {
		case STOP:
			if (std::find(m_protection.begin(), m_protection.end(), RIGHT_WAY) != m_protection.end()) return true;
			return false;
			break;
		case SPEED_LIMIT:
			if (std::find(m_protection.begin(), m_protection.end(), RIGHT_WAY) != m_protection.end()) return true;
			return false;
			break;
		case OUT_OF_GAS:
			if (std::find(m_protection.begin(), m_protection.end(), EXTRA_TANK) != m_protection.end()) return true;
			return false;
			break;
		case FLAT_TIRE:
			if (std::find(m_protection.begin(), m_protection.end(), PUNCTURE_PROOF) != m_protection.end()) return true;
			return false;
			break;
		case ACCIDENT:
			if (std::find(m_protection.begin(), m_protection.end(), DRIVING_ACE) != m_protection.end()) return true;
			return false;
			break;
	}
}

bool Player::isAffected() {
	if (m_effect != NOTHING) return true;
	return false;
}

//Check if player has won

bool Player::hasWon() {
	if (m_travelledDistance == 1000) return true;
	return false;
}

//Make replay the player

bool Player::rePlay() {
	if (m_rePlay) {
		m_rePlay = false;
		return true;
	}
	else return false;
}
