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

int C, N, K, M, Len[51];
double T[51][51];

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> K >> M;

		for (int i=0; i<N; ++i)
			cin >> Len[i];

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				scanf("%lf", &T[i][j]);

		double D[5][51];
		memset(D, 0, sizeof(D));

		D[Len[0]][0] = 1;

		for (int min=Len[0]+1; min<=K+4; ++min) {
			for (int cur=0; cur<N; ++cur) {
				for (int bef=0; bef<N; ++bef) {
					D[min%5][cur] = 0;
					if (min < Len[cur]) continue;
					else D[min%5][cur] += D[(min-Len[cur])%5][bef] * T[bef][cur];
				}
			}
		}

		for (int i=0; i<M; ++i) {
			int Like;
			cin >> Like;
			double ans=0;
			for (int m=K+1; m<=K+Len[Like]; ++m)
				ans += D[m%5][Like];
			printf("%.8lf ", ans);
		}

		cout << endl;
	}


	return 0;
}

