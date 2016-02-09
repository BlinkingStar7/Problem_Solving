#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

const int MAX = 987654321;
int tW, Graph[501][501], N;

int main() {
	cin >> tW;

	while (tW--) {
		cin >> N;

		for (int i=0; i<N; ++i) 
			for (int j=i+1; j<N; ++j) {
				scanf("%d", &Graph[i][j]);
				Graph[j][i] = Graph[i][j];
			}

		int ans = 0;

		for (int i=0; i<N; ++i) {
			for (int j=i+1; j<N; ++j) {
				int cand = MAX;
				for (int k=0; k<N; ++k) {
					if (k==i || k==j) continue;
					cand = min(cand, Graph[i][k] + Graph[k][j]);
				}
				if (cand < Graph[i][j]) ans = -1;
				else if (cand > Graph[i][j]) ans += Graph[i][j];
			}
			if (ans == -1) break;
		}
		cout << ans << endl;

	}
	return 0;
}

