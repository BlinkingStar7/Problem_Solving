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

int testNum, N, K;
typedef struct City {
	int L, M, G;
} C;
C City [5001];

bool compare (C a, C b) { return a.L < b.L; }

bool Decision (int len) {
	long long num=0;
	for (int i=0; i<N; ++i) {
		if (City[i].L <= len)
			num += City[i].M/City[i].G + 1;
		else if (City[i].L - City[i].M <= len)
			num += (len - (City[i].L - City[i].M))/City[i].G +1;
	}

	return num >= K;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> K;
		
		for (int i=0; i<N; ++i)
			scanf("%d %d %d", &City[i].L, &City[i].M, &City[i].G);
		
		sort(City, City+N, compare);
		
		int lo = 0, hi = 8030000;
		for (int it=0; it<100; ++it) {
			int mid = (lo+hi)/2;
			if (Decision(mid)) hi = mid;
			else lo = mid;
		}

		cout << hi << endl;
	}


	return 0;
}

