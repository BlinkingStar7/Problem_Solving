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

int M, N, invest[301][21], D[301][21];
int main () {
	cin >> M >> N;

	for (int i=0; i<M; ++i) {
		int m;
		scanf("%d", &m);
		for (int j=0; j<N; ++j)
			scanf("%d", &invest[m][j]);
	}
	
	for (int money = 0; money<=M; ++money) {
		for (int comp = N-1; comp>=0; --comp) {
			if (money == 0) D[money][comp] = 0;
			else {
				for (int i=0; i<=money; ++i)
					D[money][comp] = max(D[money][comp], invest[i][comp] + D[money-i][comp+1]);
			}
		}
	}

	printf("%d\n", D[M][0]);
	int money = M;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<=money; ++j) {
			if (D[money][i] == D[money-j][i+1] + invest[j][i]) {
				printf("%d ", j);
				money -= j;
				break;
			}
		}
	}

	return 0;
}

