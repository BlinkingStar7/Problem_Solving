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

int testNum, N, M;
double Pos[201];

int Decision (double len, int num, int cur) {
	if (num == 1) return 1;

	for (int next = cur+1; next<M; ++next)
		if (Pos[next]-Pos[cur] >= len)
			return Decision (len, num-1, next);
	return 0;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> M;
		for (int i=0; i<M; ++i)
			cin >> Pos[i];

		sort(Pos, Pos+M);
		
		double lo = 0, hi = 240;

		while (hi - lo > 0.00001) {
			double mid = (lo+hi)/2;
			if (Decision (mid, N, 0)) lo = mid;
			else hi = mid;
		}

		printf("%.2lf\n", hi);

	}


	return 0;
}

