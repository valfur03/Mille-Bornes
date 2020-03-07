#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <vector>
#include "Card.h"

class Player {
public:
	Player();
	Player(const Player& player);
	Player(const std::string& name);

	void dispHand(); //Display player's card one by one
	void pickCard(std::vector<Card*>& cardsStack, const int& nbCards); //Add a card to the player's hand

private:
	std::string m_playerName; //Player name
	int m_nbCards; //Number of cards in hand
	std::vector<Card *> m_hand; //Hand (cards vector)
	std::vector<Protection> m_protection; //Safety cards
	int m_travelledDistance; //Sum of distance's cards
	bool m_speedLimit; //Under speed limit or not
	Effect m_effect; //Effect (hazard cards) on the player
};

#endif