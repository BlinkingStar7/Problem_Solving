#include <iostream>
using namespace std;
#define MAX 987654321

int M, N, Coin[10];

int Solve (int remain) {
	if (remain < 0) return MAX;
	else if (remain == 0) return 0;
	int ret = MAX;
	for (int i=0; i<N; ++i)
		ret = min (ret, 1 + Solve(remain - Coin[i]));
	return ret;
}

int main() {
	cin >> M >> N;
	for (int i=0; i<N; ++i)
		cin >> Coin[i];

	cout << Solve(M) << endl;
	return 0;
}

