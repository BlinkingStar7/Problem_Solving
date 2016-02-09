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

int digit[10], cnt = 0;

int isPrime(int n) {
	int i;
	for (i=2; i*i<n; ++i)
		if (n % i == 0) return false;
	return !(n == i*i);
}

void Solve(int n) {
	int i, flag = 0;

	for (i=0; i<10; ++i)
		if (digit[i]) {
			flag = 1;
			--digit[i];
			Solve(10*n + i);
			++digit[i];
		}
	if (!flag && isPrime(n)) {cnt = 1; cout << n << ' ';}
	
}

int main () {
	int n;
	cin >> n;
	while (n != 0) {
		++digit[n%10];
		n/=10;
	}

	Solve(0);
	if (cnt == 0) cout << 0 << endl;
	return 0;
}

