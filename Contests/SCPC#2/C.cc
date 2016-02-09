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

const int MAX = 98765321;

int testNum, X, Y, K, H[101][101], D[101][101][11];

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		cin >> X >> Y >> K;
		for (int i=0; i<=Y; ++i)
			for (int j=0; j<=X; ++j)
				scanf("%d", &H[i][j]);

		for (int y=Y; y>=0; --y) {
			for (int x=X; x>=0; --x) {
				for (int k=K; k>=0; --k) {
					int &cur = D[y][x][k];
					if (y==Y && x==X) {
						cur = (k==K) ? 0 : MAX;
						continue;
					}
					cur = MAX;
					if (x<X) {
						int cost = abs(abs(H[y][x])-abs(H[y][x+1]));
						int nextK = k + (H[y][x+1]<0 ? 1 : 0);
						if (nextK > K) nextK = K;
						cur = min(cur, cost + D[y][x+1][nextK]);
					}
					if (y<Y) {
						int cost = abs(abs(H[y][x])-abs(H[y+1][x]));
						int nextK = k + (H[y+1][x]<0 ? 1 : 0);
						if (nextK > K) nextK = K;
						cur = min(cur, cost + D[y+1][x][nextK]);
					}
				}
			}
		}
		printf("Case #%d\n", tn);
		printf("%d\n", D[0][0][0]);
	}

	return 0;
}

