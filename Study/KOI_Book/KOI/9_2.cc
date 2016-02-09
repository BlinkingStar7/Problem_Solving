#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int cnt = 0, N, C[4] = {1, 3, 7, 9};

int isPrime (int x) {
	if (x < 2) return 0;
	for (int i=2; i*i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}


void Solve (int left, int len) {
	if (len == N) {
		printf("%d\n", left);
		++cnt;
		return;
	}

	for (int c=0; c<4; ++c)
		if (isPrime(left*10 + C[c]))
			Solve (left*10 + C[c], len + 1);
}


int main() {
	cin >> N;
	
	Solve(2, 1);
	Solve(3, 1);
	Solve(5, 1);
	Solve(7, 1);
	cout << cnt << endl;

	return 0;
}



