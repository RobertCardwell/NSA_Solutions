#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {

// Note: include the compiler switch "-std=c++11" to make the compiler accept
// the extended initialization format of the "rules" vector.

	// Write the heading
	cout << setw(12) << left << "deal"
	     << setw(13) << left << "player"
	     << setw(10) << left << "seen"
	     << setw(11) << left << "writeDown"
	     << setw(14) << left << "playerCard"
	     << setw(12) << left << "match" << endl << endl;

	int match_count = 0;
	int total_deals_won = 0;

	for (int deal = 0; deal <= 255; deal++) {

		vector<int> playerCard(4);
		vector<int> rules { 00, 01, 10, 11 };
		int deal_was_won = 0;

		// Store the value of each player's card.
		for (int player = 0; player <= 3; player++) {
			playerCard[player] = (deal >> (2 * player)) & 0x03;
		}

		// Process the current deal for each player.
		for (int player = 0; player <= 3; player++) {

			int seen = ((playerCard[(player + 1) % 4] & 0x03)
					^ (playerCard[(player + 2) % 4] & 0x03)
					^ (playerCard[(player + 3) % 4] & 0x03));

			// Generate the suit to write down.
			int writeDown = (seen ^ rules[player]) & 0x03;

			// Test for a match of the player's card with
			// what he wrote down.
			int match = bool(playerCard[player] == writeDown);

			// Write out all the variables for the current player.
			// Writing them in binary makes it easy to check that
			// the program works correctly.
			cout << setw(14) << left << bitset<8>(deal)
			     << setw(12) << left << bitset<2>(player)
			     << setw(12) << left << bitset<2>(seen)
			     << setw(12) << left << bitset<2>(writeDown)
			     << setw(12) << left << bitset<2>(playerCard[player])
			     << setw(2) << left << match << flush;

			if (match != 0) {
				cout << " <----" << endl;
				match_count++;
				deal_was_won = 1;
			} else
				cout << endl;
		}
		// Write a line between each deal.
		cout << "--------------------------------" << flush;
		cout << "--------------------------------" << endl;

		if (deal_was_won == 1)
			total_deals_won++;
	}
	// Write the heading again
	cout << setw(12) << left << "deal"
	     << setw(13) << left << "player"
	     << setw(10) << left << "seen"
	     << setw(11) << left << "writeDown"
	     << setw(14) << left << "playerCard"
	     << setw(12) << left << "match" << endl << endl;

	cout << "match_count: " << match_count << ", total_deals_won: " << flush;
	cout << total_deals_won << endl;

	return 0;
}
