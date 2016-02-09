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

int testNum, M;
double N, P;

int Decision (double c) {
	double left=N, interest=P/1200;

	for (int m=1; m<=M; ++m) {
		left = left*(1+interest);
		left -= c;
	}

	return left <= 0;
}
int main () {
	cin >> testNum;

	while (testNum--) {

		cin >> N >> M >> P;

		double lo = 0, hi = 100000000;
		for (int it=0; it<100; ++it) {
			double mid = (lo+hi)/2;
			if (Decision (mid)) hi = mid;
			else lo = mid;
		}
		printf("%.10lf\n", hi);

	}


	return 0;
}

