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
using namespace std;

int testNum, N;
pair<double, double> Pos[101];
double Dis[101][101];

double Distance (int a, int b) {
	return (Pos[a].first-Pos[b].first)*(Pos[a].first-Pos[b].first) + 
		(Pos[a].second-Pos[b].second)*(Pos[a].second-Pos[b].second);
}

int Decision(double len) {
	queue<int> q;
	q.push(0);
	vector<int> chk (N, 0);
	chk[0] = 1;
	int seen = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		++seen;
		for (int i=0; i<N; ++i) {
			if (chk[i]==0 && Dis[cur][i] <= len) {
				chk[i] = 1;
				q.push(i);
			}

		}
	}
	return seen == N;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			cin >> Pos[i].first >> Pos[i].second;

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				Dis[i][j] = Distance(i, j);

		double lo = 0, hi = 1000*1000;
		for (int it=0; it<100; ++it) {
			double mid = (lo+hi)/2;
			if (Decision(mid)) hi=mid;
			else lo=mid;
		}

		printf("%.2lf\n", sqrt(lo));
	}


	return 0;
}

