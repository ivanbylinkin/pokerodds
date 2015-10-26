// CPE 305
// Project 3 - Poker Odds
#include <iostream>
#include <ctime>

using namespace std;

// card holds properties about cards
class card{
public:
	enum suit { clubs, diamonds, hearts, spades };

	suit show_suit(){ return s;  }
	int show_value(){ return value; }
	
	void create_card(){
		s = rand_suit();
		value = rand() % 14;
	}
private:
	suit s;
	int value;
	
	suit rand_suit(){
		suit arr[4] = { clubs, diamonds, hearts, spades };
		int r = rand() % 4;
		return arr[r];
	}
};

// deck holds 52 cards
// only 4 cards per value, 1 of each suit
// deck contains suffles and deals
class deck{
public:
	void create_deck(){
		// while loop will ensure it will keep going until deck is properly filled
		int deck_size = 0, club_size = 0, diamond_size = 0, spade_size = 0;
		int clubs[13], diamonds[13], hearts[13], spades[13];
		int deck_cards = { clubs, diamonds, hearts, spades };
		bool indexOf(int value, int arr[], int size){
			for (int i = 0; i < size; i++){
				if (arr[i] == value){ return true; }
			}
			return false;
		}
		while (deck_size < 52){
			// initialize a card
			card tmp;
			tmp.create_card();
			// check current array

		}
	}
private:
	card dck[52];
};

// main is used to seed the random numbers
// main also makes the calls to functions
int main(){

	for (int i = 0; i < 52; i++){
		card tst;
		tst.create_card();

		cout << "card suit: " << tst.show_suit() << " card value: " << tst.show_value() << endl;
	}

	cout << "Please press enter to continue..." << endl;
	getchar();

	return 0;
}
