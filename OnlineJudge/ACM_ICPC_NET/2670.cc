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

int N;
int main () {
	cin >> N;
	double cur = 1, Max = 0;
	for (int i=0; i<N; ++i) {
		double n;
		scanf("%lf", &n);
		cur = max(cur, 1.0);
		cur *= n;
		Max = max (Max, cur);
	}
	printf("%.3lf\n", Max);

	return 0;
}

