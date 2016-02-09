#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

string str;

long long Solve (long long up, long long  n, long long  l, long long  h) {
	if (n == str.size()) return l-1;

	long long mid = (l+h)/2;

	if (up && str[n] == '0' || !up && str[n] == '1')
		return Solve(1, n+1, mid+1, h);
	return Solve(0, n+1, l, mid);
}
int main() {
	long long tN;
	cin >> tN;

	while (--tN >= 0) {
		cin >> str;
		long long h = 1;
		for (long long i=1; i<=str.size(); ++i)
			h *= 2;
		cout << Solve (0, 0, 1, h) << endl;

	}

	return 0;
}


