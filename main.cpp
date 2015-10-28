// CPE 305
// Project 3 - Poker Odds
#include <iostream>
#include <ctime>

using namespace std;

// card holds properties about cards
class card{
public:
	enum suit { clubs, diamonds, hearts, spades };

	suit show_suit(){ return s; }
	int show_value(){ return value; }

	void create_card(){
		s = rand_suit();
		value = (rand() % 13) + 1;
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
	enum suit { clubs, diamonds, hearts, spades };
	// decks are randomly generated meaning each shuffle is a new random deck
	void shuffle(){
		// while loop will ensure it will keep going until deck is properly filled
		int deck_size = 0;
		int counts[4][13];
		// nullify arrays to use for checks
		nullifyArr(counts[clubs], 13);
		nullifyArr(counts[diamonds], 13);
		nullifyArr(counts[hearts], 13);
		nullifyArr(counts[spades], 13);

		while (deck_size < 52){
			// initialize a card
			card tmp;
			tmp.create_card();
			// check current card
			int value = tmp.show_value(),
			card_suit = tmp.show_suit();
			// check index of array
			bool exists = counts[card_suit][value] == -1 ? false : true;
			if (!exists){
				dck[deck_size] = tmp;
				deck_size++;
			}
		}
	}

	void show_deck(){
		for (int i = 0; i < 52; i++){
			cout << "Suit: " << dck[i].show_suit() << " Value: " << dck[i].show_value() << endl;
		}
	}
private:
	card dck[52];

	void nullifyArr(int arr[], int n){
		for (int i = 0; i < n; i++){
			arr[i] = -1;
		}
	}
};

// main is used to seed the random numbers
// main also makes the calls to functions
int main(){
	// seed the generator
	srand(time(NULL));
	// make the deck
	deck newDeck;
	newDeck.shuffle();
	newDeck.show_deck();

	cout << "Please press enter to continue..." << endl;
	getchar();

	return 0;
}
