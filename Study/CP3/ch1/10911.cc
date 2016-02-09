#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double INF = 1e8;
int N;
ii pos[17];
double ans;

inline double getDist (int i, int j) {
	return hypot(pos[i].first-pos[j].first, pos[i].second-pos[j].second);
}

double greedy(vector<bool> &sel, bool heu) {
	double cur = 0;

	for (int i=0; i<2*N; ++i) {
		if (sel[i]) continue;
		double cand = INF;
		int best = -1;
		for (int j=0; j<2*N; ++j) {
			if (!sel[j] && j != i) {
				if (getDist(i, j) < cand) {
					best = j;
					cand = min (cand, getDist(i, j));
				}
			}
		}
		if (!heu) 
			sel[i] = sel[best] = true;
		cur += cand;
	}

	return heu ? cur/2 : cur;
}

void solve(vector<bool> &sel, double cur) {
	int first = -1;
	for (int i=0; i<2*N; ++i) if(!sel[i]) {first = i; break;}
	if (first == -1) {
		ans = min(ans, cur);
		return;
	}


	for (int i=0; i<2*N; ++i)
		if (!sel[i] && i != first) {
			sel[first] = sel[i] = true;
			solve(sel, cur + getDist(first, i));
			sel[first] = sel[i] = false;
		}
}

	


			
int main() {
	for (int c=1; ; ++c) {
		ans = INF;
		cin >> N;
		if (!N) break;
		for (int i=0; i<2*N; ++i) {
			char temp[20];
			scanf("%s%d%d",temp, &pos[i].first, &pos[i].second);
		}
		sort (pos, pos+2*N);

		vector<bool> sel(2*N, false);
		ans = min (ans, greedy(sel, false));
		fill(sel.begin(), sel.end(), false);
		solve(sel, 0);

		printf("Case %d: %.2lf\n", c, ans);
	}
	return 0;
}

