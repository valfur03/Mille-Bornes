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

	std::string getName();
	std::vector<Protection> getProtection();
	void details();
	void dispHand(); //Display player's card one by one
	bool pickCard(std::vector<Card*>& cardsStack, const std::vector<Card*>& discardStack, const int& nbCards = 1); //Add a card to the player's hand
	bool playCard(const int& selectedCard, const std::vector<Player*>& playersList);
	void disCard(const int& selectedCard, std::vector<Card*>& discardCardsStack);
	void getAttack(const Effect& effect);
	bool isProtected(const Effect& effect);
	bool isAffected();
	bool hasWon();
	bool rePlay();

private:
	std::string m_name; //Player name
	int m_nbCards; //Number of cards in hand
	std::vector<Card*> m_hand; //Hand (cards vector)
	std::vector<Protection> m_protection; //Safety cards
	int m_travelledDistance; //Sum of distance's cards
	int m_bornesLimit; //Limit of 2 200 distance's cards
	bool m_speedLimit; //Under speed limit or not
	Effect m_effect; //Effect (hazard cards) on the player
	bool m_rePlay;
};

#endif