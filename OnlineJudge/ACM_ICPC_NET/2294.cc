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
#include <numeric>
using namespace std;

int N, K, Memo[10001], Coin[101]; 
int main () {
	cin >> N >> K;
	memset(Memo, -1, sizeof(Memo));
	Memo[0] = 0;
	for (int i=0; i<N; ++i)
		cin >> Coin[i];

	sort (Coin, Coin+N);
	for (int i=0; i<N; ++i)
		for (int k=0; k+Coin[i]<=K; ++k)
			if (Memo[k] != -1)
				if (Memo[k+Coin[i]] == -1) Memo[k+Coin[i]] = Memo[k]+1;
				else Memo[k+Coin[i]] = min (Memo[k+Coin[i]], Memo[k]+1);

	cout << Memo[K] << endl;

	return 0;
}

