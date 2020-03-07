#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "../includes/Distance.h"
#include "../includes/Hazard.h"
#include "../includes/Remedy.h"
#include "../includes/Safety.h"
#include "../includes/Player.h"

std::vector<Card*> initializeCardsList();
void breakLine();
std::vector<Player*> initializePlayersList(const int& nbPlayers);

int main() {
	//Initialize cards' list

	std::vector<Card*> cardsList = initializeCardsList(); //Create a list of the game's cards
	std::vector<Card*> cardsStack = cardsList; //Create the cards' stack
	std::shuffle(std::begin(cardsStack), std::end(cardsStack), std::default_random_engine(time(0))); //Suffle the cards' stack
	std::vector<Card*> discardCardsStack; //Create the discard cards' stack

	//Initialize players' list

	int nbPlayers; //Number of players

	breakLine();

	do {
		std::cout << "Entrez le nombre de joueurs : ";
		std::cin >> nbPlayers;
		if (nbPlayers < 2 || nbPlayers > 4) {
			breakLine();

			std::cout << "Voue ne pouvez pas jouer a " << nbPlayers << " joueurs. Une partie se deroule avec 2-4 joueurs." << std::endl;
		}
	} while (nbPlayers < 2 || nbPlayers > 4);

	breakLine();

	std::vector<Player*> playersList = initializePlayersList(nbPlayers); //List of the players

	//Deal 6 cards to each player
	for (int i = 0; i < nbPlayers; i++) playersList[i]->pickCard(cardsStack, 6);
}

//Return an unshuffled cards' list

std::vector<Card*> initializeCardsList() {
	std::vector<Card*> cardsList; //Initialize the cards' list

	//Add safeties to the cards' list
	cardsList.push_back(new Safety("Vehicule prioritaire", RIGHT_WAY));
	cardsList.push_back(new Safety("Citerne d'essence", EXTRA_TANK));
	cardsList.push_back(new Safety("Increvable", PUNCTURE_PROOF));
	cardsList.push_back(new Safety("As du volant", DRIVING_ACE));

	//Add hazards to the cards' list
	for (int i = 0; i < 5; i++) cardsList.push_back(new Hazard("Feu rouge", STOP));
	for (int i = 0; i < 4; i++) cardsList.push_back(new Hazard("Limite de vitesse", SPEED_LIMIT));
	for (int i = 0; i < 3; i++) cardsList.push_back(new Hazard("Panne d'essence", OUT_OF_GAS));
	for (int i = 0; i < 3; i++) cardsList.push_back(new Hazard("Crevaison", FLAT_TIRE));
	for (int i = 0; i < 3; i++) cardsList.push_back(new Hazard("Accident", ACCIDENT));

	//Add remedies to the cards' list
	for (int i = 0; i < 14; i++) cardsList.push_back(new Remedy("Feu vert", STOP));
	for (int i = 0; i < 6; i++) cardsList.push_back(new Remedy("Fin de limite de vitesse", SPEED_LIMIT));
	for (int i = 0; i < 6; i++) cardsList.push_back(new Remedy("Essence", OUT_OF_GAS));
	for (int i = 0; i < 6; i++) cardsList.push_back(new Remedy("Roue de secours", FLAT_TIRE));
	for (int i = 0; i < 6; i++) cardsList.push_back(new Remedy("Reparations", ACCIDENT));

	//Add distances to the cards' list
	for (int i = 0; i < 10; i++) cardsList.push_back(new Distance("25 bornes", 25));
	for (int i = 0; i < 10; i++) cardsList.push_back(new Distance("50 bornes", 50));
	for (int i = 0; i < 10; i++) cardsList.push_back(new Distance("75 bornes", 75));
	for (int i = 0; i < 12; i++) cardsList.push_back(new Distance("100 bornes", 100));
	for (int i = 0; i < 4; i++) cardsList.push_back(new Distance("200 bornes", 200));

	return cardsList;
}

//Print a line of -

void breakLine() {
	std::cout << std::endl << "------------------------------\n" << std::endl;
}

//Return a players' list

std::vector<Player*> initializePlayersList(const int& nbPlayers) {
	std::vector<Player*> playersList;

	std::cout << "Entrez le nom des joueurs du plus jeune au plus vieux" << std::endl;
	std::string playerName;
	for (int i = 0; i < nbPlayers; i++) {
		std::cout << "Entrez le nom du joueur " << i + 1 << " : ";
		std::cin >> playerName;
		playersList.push_back(new Player(playerName));

		breakLine();
	}

	return playersList;
}