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

int N, K, Memo[2][10001], Coin[101];

int main () {
	cin >> N >> K;
	for (int i=0; i<N; ++i)
		scanf("%d", Coin + i);

	for (int k=0; k<=K; k+=Coin[0])
		Memo[0][k] = 1;

	for (int n=1; n<N; ++n) {
		for (int k=0; k<=K; ++k) {
			int x = 0;
			for (int i=0; i*Coin[n]<=k; ++i) 
				x += Memo[(n-1)%2][k-i*Coin[n]];
			Memo[n%2][k] = x;
		}
	}

	cout << Memo[(N-1)%2][K] << endl;
			




	return 0;
}

