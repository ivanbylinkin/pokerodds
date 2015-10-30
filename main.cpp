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
			int value = tmp.show_value() - 1,
			card_suit = tmp.show_suit();
			// check index of array
			bool exists = counts[card_suit][value] == -1 ? false : true;
			if (!exists){
				dck[deck_size] = tmp;
				deck_size++;
				counts[card_suit][value] = 0;
			}
		}
	}
    
    void deal(card arr[], int cards){
        // check if deck needs to reshuffle
        if ((placeholder + cards) > 52){
            shuffle();
            placeholder = 0;
            cout << endl << "reshuffling deck..." << endl;
        }
        // deals out the first n cards in the deck
        for (int i=placeholder; i<cards; i++){
            arr[i] = dck[i];
        }
        // move the placeholder up
        placeholder += cards;
    }

	void show_deck(){
		for (int i = 0; i < 52; i++){
			cout << "Suit: " << dck[i].show_suit() << " Value: " << dck[i].show_value() << endl;
		}
	}
private:
	card dck[52];
    int placeholder = 0;

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
	// tell the user shuffle is occuring
    cout << "shuffling the deck" << endl;
    // make the deck
	deck newDeck;
	newDeck.shuffle();
	// ask for how many cards to deal
    cout << "how many cards should be dealt? " << endl;
    int cards;
    cin >> cards;
    // ask how many hands to compute
    cout << "how many hands should be simulated? " << endl;
    int hands;
    cin >> hands;
    for (int i=0; i<hands; i++){
        // deal the cards
        card hand[cards];
        newDeck.deal(hand, cards);
        // show the hand
        cout << endl << "hand #" << i << endl;
        char suits[4] = { 'c', 'd', 'h', 's' };
        for (int k=0; k<cards; k++){
            cout << suits[hand[k].show_suit()] << " " << hand[k].show_value() << endl;
        }
    }
    
	cout << "Please press enter to continue..." << endl;
	getchar();

	return 0;
}
