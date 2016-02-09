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
using namespace std;

int C, N, M;
double D[1001][2003];

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> M;

		memset(D, 0, sizeof(D));

		for (int m=M; m>=0; --m) {
			for (int p=2*M; p>=0; --p) {
				if (p >= N) D[m][p] = 1;
				else if (m < M) D[m][p] = 0.25*D[m+1][p+1] + 0.75*D[m+1][p+2];
			}
		}

		cout << D[0][0] << endl;
	}

	return 0;
}

