#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 987654321
int N, arr[10][10], visited[10];

int Solve(int c) {
	if (c >= N) return 0;
	int ret = MAX;
	for (int i=0; i<N; ++i) {
		if (!visited[i]){
			visited[i] = 1;
			ret = min (ret, arr[i][c] + Solve(c+1));
			visited[i] = 0;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i=0;i<N;++i)
		for (int j=0;j<N;++j)
			cin >> arr[i][j];

	cout << Solve(0) << endl;
	return 0;
}
