#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	int A, X, Y;
	cin >> A >> X >> Y;

	int ans = -1;

	if (Y > 0 && Y < A) {
		if (2*X > -A && 2*X < A) {
			ans = 1;
		}
	}
	else if (Y%A) {
		if ((Y/A)%2 == 1) {
			if (2*X > -A && 2*X < A) {
				ans = 3*(Y/(2*A))+2;
			}
		}
		else {
			if (X > -A && X < 0) {
				ans = 3*(Y/(2*A));
			}
			if (X > 0 && X < A) {
				ans = 3*(Y/(2*A)) + 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

