#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define SQR(x) ((x)*(x))
int testNum, x[3], y[3], r[3];

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> x[1] >> y[1] >> r[1] >> x[2] >> y[2] >> r[2];
		int sqrd = SQR(x[1] - x[2]) + SQR(y[1] - y[2]);
		int p;
		if (SQR(r[1] + r[2]) < sqrd) 
			p = 0;
		else if (SQR(r[1] + r[2]) == sqrd)
			p = 1;
		else if (SQR(r[1] - r[2]) < sqrd && sqrd < SQR(r[1] + r[2]))
			p = 2;
		else if (SQR(r[1] - r[2]) == sqrd) {
			if (sqrd == 0 && r[1] == r[2]) p = -1;
			else p = 1;
		}
		else 
			p = 0;
		cout << p << endl;


	}


	return 0;
}

