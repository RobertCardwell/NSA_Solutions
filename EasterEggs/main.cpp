#include <iostream>
#include <algorithm>		// next_permutation
#include <iomanip>		// setw
using namespace std;

int main() {

	// Compilation requires C++11 flag.

	// Write the table heading.
	cout << setw(10) << left << "b wins" << setw(10) << left << "c wins" << setw(10)
			<< left << "ties" << setw(10) << left << "chris_search" << endl;

	cout << "-----------------------------" << flush;
	cout << "-----------------------------" << endl << endl;

	// Chris' initial search sequence, with integers substituted for chars:
	int chris_search[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	// A counter for the total number of permutations run (i.e., iterations
	// of the do loop. There will be 12! == 479,001,600 of these.
	long int count = 0;

	do {
		int bob_number_of_wins = 0;
		int chris_number_of_wins = 0;
		int number_of_ties = 0;
    
	  // Initialize the count indicating the best strategy found, with a
		// high enough integer. This in order to keep down the size of the
		// printout. We are only interested in the top few strategies.
		int chris_number_of_wins_maximum = 55;

		for (int x = 1; x <= 11; x++) {
			for (int y = x + 1; y <= 12; y++) {

				int bob_score = x;

				int chris_score;

				for (int i = 0; i <= 11; i++) {
					if ((chris_search[i] == x) | (chris_search[i] == y)) {
						chris_score = i + 1;
						break;
					}
				}
				// Determine the winner.
				if (bob_score < chris_score)
					bob_number_of_wins++;
				if (chris_score < bob_score)
					chris_number_of_wins++;
				if (chris_score == bob_score)
					number_of_ties++;
			}
		}
		if ((chris_number_of_wins >= chris_number_of_wins_maximum)) {

			chris_number_of_wins_maximum = chris_number_of_wins;

			// Write out the variables that we are interested in.
			cout << setw(10) << left << bob_number_of_wins << setw(10)
					<< left << chris_number_of_wins << setw(10) << left
					<< number_of_ties << flush;

			for (int i = 0; i <= 11; i++)
				cout << chris_search[i] << " " << flush;

			// Write a line between each combination.
			cout << endl << "-----------------------------"
				<< "-----------------------------" << endl;
		}
		count++;

	} while (next_permutation(chris_search, chris_search + 12));

	cout << "-----------------------------" << flush;
	cout << "-----------------------------" << endl << endl;

	// Write the table heading.
	cout << setw(10) << left << "b wins" << setw(10) << left << "c wins" << setw(10)
			<< left << "ties" << setw(10) << left << "chris_search" << endl;

	cout << endl << "Number of permutations tried: " << count << endl;

	return 0;
}
