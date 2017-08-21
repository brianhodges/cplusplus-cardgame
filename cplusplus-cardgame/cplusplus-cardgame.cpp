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
using namespace std;

int main(int argc, const char * argv[]) {

	static const string suits[] = { "Spades", "Clubs", "Hearts", "Diamonds" };
	static const string ranks[] = { "Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2" };
	vector<Card> deck;

	for (int x = 0; x < sizeof(suits) / sizeof(suits[0]); x++) {
		for (int y = 0; y < sizeof(ranks) / sizeof(ranks[0]); y++) {
			Card c;
			c.set_values(suits[x], ranks[y]);
			deck.push_back(c);
		}
	}

	//Shuffle Deck
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

	for (vector<int>::size_type i = 0; i != deck.size(); i++) {
		cout << deck[i].rank + " Of " + deck[i].suit << endl;
	}

	cout << endl << "Deck Size: " << deck.size() << endl;

	cin.get();
	return 0;
}

