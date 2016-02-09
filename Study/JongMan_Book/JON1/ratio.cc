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

long long testNum, N, M;

int Decision (long long G) {
	long long P = (long long)(M*100/N) + 1;
	return 100*(M + G) - N*P - G*P >= 0;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> M;
		
		long long lo = 0, hi = 2000000000;

		for (int it=0; it<100; ++it) {
			long long mid = (lo+hi)/2;
			if (Decision(mid)) hi = mid;
			else lo = mid;
		}

		if (Decision(hi))
			cout << hi << endl;
		else
			cout << -1 << endl;


	}


	return 0;
}

