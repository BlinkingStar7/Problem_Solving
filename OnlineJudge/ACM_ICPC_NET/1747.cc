#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <numeric>
using namespace std;

int append[5] = {0, 1, 3, 7, 9}, ans = 0x7fffffff, N;

void Solve(int num, int digit) {
	if (digit > log(N)+2) return;
	if (num < N) {
		for (int i=0; i<5; ++i)
			Solve (append[i] * pow(10, digit+1) + num*10 + append[i], digit+2);
	}
	else {
		if (num <= 1) return;
		int sqrtn = sqrt(num);
		for (int i=2; i<=sqrtn; ++i)
			if (num % i == 0) return;
		if (ans > num) ans = num;
	}
}

int main () {
	cin >> N;
	Solve (0, 0);
	for (int i=0; i<10; ++i)
		Solve (i, 1);

	cout << ans << endl;
	return 0;
}

