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

int N, arr[11][11], V[11], MAX = 0x7fffffff;

void greedySolve(int r, int sum) {
	if (r == N) {
		if (sum < MAX) MAX = sum;
		return;
	}

	int min = -1;
	for (int i=0; i<N; ++i) {
		if (min == -1 && !V[i])
			min = i;
		if (!V[i] && (arr[r][min] > arr[r][i]))
			min = i;
	}

	V[min] = 1;
	greedySolve(r+1, sum+arr[r][min]);
	V[min] = 0;
}

void Solve(int r, int sum) {
	if (sum >= MAX) return;
	if (r == N) MAX = sum;

	for (int i=0; i<N; ++i)
		if (!V[i]) {
			V[i] = 1;
			Solve(r+1, sum+arr[r][i]);
			V[i] = 0;
		}
}

int main () {
	cin >> N;

	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			cin >> arr[i][j];

	greedySolve(0, 0);
	Solve(0, 0);
	cout << MAX << endl;

	return 0;
}

