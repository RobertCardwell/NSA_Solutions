#include <iostream>
#include <algorithm>		// find, sort
#include <vector>		// vector
#include <iterator>		// printing of vector
using namespace std;

// This is the target we will use to test any proposed solution:
vector<int> pairSums { 6, 8, 10, 12, 14, 16 };

bool validPair(int a, int b) {
	// For a given pair of weights, determine if its sum is in the set of
	// specified sums of pairs.

	int sum = a + b;

	if (find(pairSums.begin(), pairSums.end(), sum) != pairSums.end()) {
		/* pairSums contains sum */
		return true;
	} else {
		/* pairSums does not contain sum */
		return false;
	}
}

int main() {

	vector<vector<int>> allSolutions;

	int numberOfSolutions = 0;

	for (int w = 1; w < 16; w++) {
		for (int x = 1; x < 16; x++) {
			for (int y = 1; y < 16; y++) {
				for (int z = 1; z < 16; z++) {
					if (validPair(w, x)
						& validPair(w, y)
						& validPair(w, z)
						& validPair(x, y)
						& validPair(x, z)
						& validPair(y, z)) {

						// Get the vector of all possible sums of pairs
						vector<int> trySums { (w + x), (w + y), (w + z),
								(x + y), (x + z), (y + z) };

						// Need to sort it before doing a comparison
						sort(trySums.begin(), trySums.end());

						// Test if it is a solution
						if (trySums == pairSums) {

							// Package the quad as a solution vector
							vector<int> solutionQuad { w, x, y, z };

							// Sort the solution vector
							sort(solutionQuad.begin(), solutionQuad.end());

							// Push the solution vector to the vector of all
							// possible solutions, but only if it is not a
							// duplicate of one already found.
							if (find(allSolutions.begin(), allSolutions.end(),
									solutionQuad) == allSolutions.end()) {

								// solutionQuad not in allSolutions, add it
								allSolutions.push_back(solutionQuad);

								// and write out solutionQuad
								copy(solutionQuad.begin(), solutionQuad.end(),
										ostream_iterator<int>(cout, " "));
								cout << endl;

								// and iterate the total number of solutions
								numberOfSolutions++;
							}
						}
					}
				}
			}
		}
	}

	cout << endl;

	cout << "The number of solutions is: " << numberOfSolutions << endl;

	return 0;
}
