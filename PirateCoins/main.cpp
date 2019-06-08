#include <iostream>

using namespace std;

int main() {

// 	The solution is to formulate the problem as follows, and then
// 	search through the possible number of coins (x):
//
//	x % 13 == 3
//	x % 12 == 5
//	x % 11 == 0
//	x < 1000

	for (int x = 1; x < 1000; x++) {
		if ((x % 13 == 3) & (x % 12 == 5) & (x % 11 == 0)) {
			cout << "The number of coins is " << x << endl;
		}
	}

	return 0;
}
