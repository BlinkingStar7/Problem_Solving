#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int tW, N, M, K, R, Board[1001][1001], Contain[1001][1001][51];

int main() {
	cin >> tW;

	while (tW--) {
		cin >> N >> M >> K >> R;
		for (int i=1; i<=M; ++i)
			for (int j=1; j<=N; ++j)
				scanf("%d", &Board[i][j]);

		for (int color=1; color<=K; ++color) {
			for (int i=1; i<=M; ++i) {
				for (int j=1; j<=N; ++j) {
					int cur = Board[i][j] == color ? 1 : 0;
					Contain[i][j][color] = cur + Contain[i][j-1][color] + Contain[i-1][j][color] - Contain[i-1][j-1][color];
				}
			}
		}

		int ans = 0;
		for (int color=1; color<=K; ++color) {
			for (int i=1; i<=M; ++i) {
				for (int j=1; j<=N; ++j) {
					int ly = i-R>=1 ? i-R : 1, lx = j-R>=1 ? j-R : 1,
						hy = i+R<=M ? i+R : M, hx = j+R<=N ? j+R : N;
					int s =  (Contain[hy][hx][color] - Contain[hy][lx-1][color] - Contain[ly-1][hx][color] + Contain[ly-1][lx-1][color]) ;
					if (s) {
						++ans;
					}

				}
			}
		}
		cout << ans << endl;

	}
	return 0;
}

