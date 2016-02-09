#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

const int MOD = 20091101;
int testNum, N, K, Doll[100*1000+1];

int Solve1() {
	vector<long long> succ(K+1);
	long long ret = 0;
	for (int i=N; i>=0; --i) {
		ret += succ[Doll[i]]++;
		ret %= MOD;
	}
	return ret;
}

int Solve2() {
	vector<int> last(N+1), succ(K+1, N+2);
	int ret = 0;
	for (int i=N; i>=0; --i) {
		last[i] = succ[Doll[i]];
		succ[Doll[i]] = i;
	}
	
	int Min = N+2;
	for (int i=0; i<=N; ++i) {
		Min = min (Min, last[i]);
		if (i + 1 == Min ) {
			++ret;
			Min = N+2;
			continue;
		}

	}

	return ret;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> K;
		for (int i=1; i<=N; ++i) {
			scanf("%d", Doll+i);
			Doll[i] = (Doll[i-1] + Doll[i])%K;
		}
		
		cout << Solve1() << " " << Solve2() << endl;
	}


	return 0;
}

