#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
using namespace std;

class Player {

public:
	vector<Card> hand;
	void deal(Card);
};

void Player::deal(Card h) {
	hand.push_back(h);
}

#endif