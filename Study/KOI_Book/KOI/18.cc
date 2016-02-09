#include <iostream>
using namespace std;

#define MIN -987654321
int N, W, Mass[100], Cost[100];

int Solve (int it, int sum) {
	if (sum > W) return MIN;
	if (it >= N) return 0;
	return max (Solve(it+1, sum), Cost[it] + Solve(it+1, sum + Mass[it]));
}

int main () {
	cin >> N >> W;
	for (int i=0; i<N; ++i)
		cin >> Mass[i] >> Cost[i];
	cout << Solve (0, 0) << endl;
	return 0;
}

