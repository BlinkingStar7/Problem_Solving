#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, P[16], cur[3], list[3] = {987654321, 0, 0};

int compare (const int& a, const int& b) {
	if (a > b) return 1;
	else return a == b ? 0 : -1;
}

void Solve(int n) {
	if (n == N) {
		if (cur[0] < cur[1] || cur[1] < cur[2]) return;
		if (cur[0] - cur[2] < list[0] - list[2])
			for (int i=0; i<3; ++i) list[i] = cur[i];
		else if (cur[0] - cur[2] == list[0] - list[2])
			if (cur[0] < list[0])
				for (int i=0; i<3; ++i) list[i] = cur[i];
		return;
	}

	for (int i=0; i<3; ++i) {
		cur[i] += P[n];
		Solve(n+1);
		cur[i] -= P[n];
	}
}
			
int main() {
	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> P[i];

	Solve(0);
	
	printf("%d %d %d\n", list[0], list[1], list[2]);
	return 0;
}

