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

int N, A[21];
bool Visited[11];
vector<int> X;

bool Solve() {
	int first=-1;
	for (int i=0; i<2*N; ++i)
		if (A[i] == -1) {
			first = i;
			break;
		}
	
	if (first == -1) return true;

	for (int i=0; i<N; ++i) {
		if (!Visited[i]) {
			int num = X[i], second = first + X[i] + 1;

			if (second >= 2*N || A[second] != -1)
				continue;

			Visited[i] = true;
			A[first] = A[second] = num;
			if (Solve()) return true;
			A[first] = A[second] = -1;
			Visited[i] = false;
		}
	}

	return false;
}




int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		X.push_back(t);
	}

	sort(X.begin(), X.end());
	memset(A, -1, sizeof(A));

	if (Solve()) {
		for (int i=0; i<2*N; ++i)
			printf("%d ", A[i]);
		puts("");
	}
	else
		printf("-1\n");


	return 0;
}

