// cplusplus-cardgame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"
#include "player.h"
using namespace std;

int main(int argc, const char * argv[]) {

	static string suits[] = { "Spades", "Clubs", "Hearts", "Diamonds" };
	static string ranks[] = { "Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2" };
	Player player1;
	Player player2;
	vector<Card> deck;

	//Shuffle Ranks before assembling deck
	random_shuffle(std::begin(ranks), std::end(ranks));

	//Assemble Playing Deck
	for (int x = 0; x < sizeof(suits) / sizeof(suits[0]); x++) {
		for (int y = 0; y < sizeof(ranks) / sizeof(ranks[0]); y++) {
			Card c;
			c.set_values(suits[x], ranks[y]);
			deck.push_back(c);
		}
	}

	//Shuffle Full Deck
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

	//Deal Player Hands
	for (vector<int>::size_type i = 0; i != deck.size(); i++) {
		(i % 2 == 0) ? (player1.hand.size() < 5 ? player1.deal(deck[i]) : false) : (player2.hand.size() < 5 ? player2.deal(deck[i]) : false);
	}

	//Display Player 1 Hand
	cout << endl << endl << "Player 1 Hand:" << endl;
	cout << string(14, '-') << endl;
	for (vector<int>::size_type i = 0; i != player1.hand.size(); i++) {
		cout << player1.hand[i].rank << " Of " << player1.hand[i].suit << endl;
	}

	//Display Player 2 Hand
	cout << endl << endl << "Player 2 Hand:" << endl;
	cout << string(14, '-') << endl;
	for (vector<int>::size_type i = 0; i != player2.hand.size(); i++) {
		cout << player2.hand[i].rank << " Of " << player2.hand[i].suit << endl;
	}

	cout << endl << endl << "DECK SIZE:" << endl;
	cout << string(10, '-') << endl;
	cout << deck.size();

	cin.get();
	return 0;
}

