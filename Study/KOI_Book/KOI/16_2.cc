#include <iostream>
using namespace std;
#define MAX 987654321
int N, M, coin[10];

int Solve(int remain, int c) {
	if (remain < 0 || c == N) return MAX;
	if (remain == 0) return 0;			
	int ret = MAX;
	for (int i=0; coin[c]*i <= remain; ++i)
		ret = min (ret, i + Solve(remain - coin[c]*i, c+1));
	return ret;
}

int main() {
	cin >> M >> N;
	for (int i=0; i<N; ++i)
		cin >> coin [i];
	cout << Solve (M, 0) << endl;
	return 0;
}

