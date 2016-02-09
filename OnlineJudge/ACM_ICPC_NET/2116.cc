#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, Dice[10001][7], Solve[3][7];
const int next[7] = {5, 3, 4, 1, 2, 0};

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) 
		for (int j=0; j<6; ++j)
			scanf("%d", &Dice[i][j]);

	for (int i=1; i<=6; ++i)
		Solve[N%2][i] = 0;

	for (int n=N-1; n>=0; --n) {
		for (int s=6; s>=1; --s) {
			int startIndex;
			for (int i=0; i<6; ++i)
				if (Dice[n][i] == s) {
					startIndex = i;
					break;
				}
			int nextIndex = next[startIndex], nextNum = Dice[n][nextIndex], m = 0;

			for (int i=0; i<6; ++i)
				if (Dice[n][i] != s && Dice[n][i] != nextNum)
					m = max (m, Dice[n][i]);

			Solve[n%2][s] = m + Solve[(n+1)%2][nextNum]; 
		}
	}
	int ans = 0;
	for (int i=0; i<6; ++i)
		ans = max(ans, Solve[0][i+1]);

	cout << ans << endl;
	return 0;
}


