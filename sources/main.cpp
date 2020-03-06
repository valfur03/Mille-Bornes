#include <iostream>
#include "../includes/Distance.h"
#include "../includes/Hazard.h"
#include "../includes/Remedy.h"
#include "../includes/Safety.h"
#include "../includes/Player.h"

std::vector<Card*> initializeCardsList();

int main() {
	std::vector<Card *> cardsList = initializeCardsList();
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