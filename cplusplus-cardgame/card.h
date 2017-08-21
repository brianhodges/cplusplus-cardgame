#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;



class Card {

public:
	string suit, rank;
	void set_values(string, string);
};



void Card::set_values(string s, string r) {
	suit = s;
	rank = r;
}

#endif