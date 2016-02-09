#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

struct Lamp {
	int X, D, T, P;
};

bool compare(const Lamp &a, const Lamp &b) {
	return a.X < b.X;
}


int N, L;
Lamp Arr[100001];

int main () {
	cin >> N >> L;
	for (int i=0; i<N; ++i) {
		int x, d, t, p;
		scanf("%d %d %d %d", &x, &d, &t, &p);
		Arr[i] = (Lamp) {x, d, t, p};
	}

	sort (Arr, Arr+N, compare);


	return 0;
}

