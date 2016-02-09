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

long long X[10001], Y[10001];
int main () {
	int N;
	cin >> N;

	for (int i=0; i<N; ++i)
		scanf("%lld %lld", X+i, Y+i);

	double area = 0.0;
	for (int i=0; i<N; ++i) {
		area += X[i] * Y[(i+1)%N] - X[(i+1)%N] * Y[i];
	}

	printf("%.1lf\n", abs(area)/2.0);


	return 0;
}

