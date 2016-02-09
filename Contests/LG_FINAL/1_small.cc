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

int testNum, N, Pos[100001];

double ground(double x, int i) {
	return Pos[i]+(double)(Pos[i+1]-Pos[i])*(x-i);
}
double diff(double x, int ii) {
	double m=0;
	for (int i=0; i<N; ++i) {
		double gradient = Pos[i+1]-Pos[i];
		double cur = Pos[i] + (x-i)*gradient;
		if (cur > m) m = cur;
	}
	return m - ground(x, ii);
}


int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		for (int i=0; i<=N; ++i) 
			scanf("%d", Pos+i);

		double ans = 987654321;
		for (int i=0; i<N; ++i) {
			double lo = i, hi = i+1;
			for (int it=0; it<100; ++it) {
				double aab = (2*lo + hi)/3;
				double abb = (lo + 2*hi)/3;
				if (diff(aab, i) < diff(abb, i))
					hi = abb;
				else
					lo = aab;
			}
			ans = min (ans, diff((lo+hi)/2, i));

		}
		printf("%.3lf\n", ans);
	}
	return 0;
}

