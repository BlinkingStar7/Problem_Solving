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

int N, R, r;
int main () {
	cin >> N >> R >> r;
	bool flag = true;
	const double epsilon = 1e-10;
	if (2*r < R) {
		double t = 2*asin((double)r/(R-r));
		double PI = 2*asin(1);
		if (t*N > 2*PI + epsilon)
			flag = false;
	}
	else if (2*r == R) {
		if (N > 2) flag = false;
	}
	else if (r<=R) {
		if (N > 1) flag = false;
	}
	else
		flag = false;

	if (!flag)
		cout << "NO"<< endl;
	else
		cout << "YES" << endl;

	return 0;
}

