#include <iostream>
#define MIN -987654321
using namespace std;

int B, N, Cost[21];

int Solve (int n, int sum) {
	if (sum > B) return MIN;
	if (n >= N) return 0;
	int ret = sum;
	ret = max (Cost[n] + Solve(n+1, sum + Cost[n]), Solve(n + 1, sum));
	return ret;
}

int main() {
	cin >> B >> N;
	for (int i=0; i<N; ++i)
		cin >> Cost[i];
	cout << Solve(0, 0) << endl;
	return 0;
}

