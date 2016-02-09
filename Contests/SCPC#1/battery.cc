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
const int MAX = 987654321;

int tN, N, pX[101][2], pY[101][2];
int main () {
	setbuf(stdout, NULL);
	cin >> tN;
	for (int t=1; t<=tN; ++t) {
		cin >> N;
		vector<int> x, y;
		for (int i=0; i<N; ++i) {
			scanf("%d %d %d %d", &pX[i][0], &pY[i][0], &pX[i][1], &pY[i][1]);
			x.push_back(pX[i][0]);
			x.push_back(pX[i][1]);
			y.push_back(pY[i][0]);
			y.push_back(pY[i][1]);
		}

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		
		double x_max=MAX, y_max=MAX;
		for (int i=0; i<x.size(); ++i) {
			for (int j=i; j<x.size(); ++j) {
				double pos = (x[i]+x[j])/2.0;
				double cand = 0;
				for (int p=0; p<N; ++p)
					cand = max(cand, min(abs(pX[p][0]-pos), abs(pX[p][1]-pos)));
				if (cand < x_max) x_max = cand;
			}
		}
		
		for (int i=0; i<y.size(); ++i) {
			for (int j=i; j<y.size(); ++j) {
				double pos = (y[i]+y[j])/2.0;
				double cand = 0;
				for (int p=0; p<N; ++p)
					cand = max(cand, min(abs(pY[p][0]-pos), abs(pY[p][1]-pos)));
				if (cand < y_max) y_max = cand;
			}
		}

		double ans = max(x_max, y_max);
		printf("Case #%d\n",t);
		if (ans == (int)ans)
			printf("%d\n", (int)ans);
		else
			printf("%.1lf\n", ans);

	}
		
	return 0;
}

