#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
long long N, D[91];

int main() {
	cin >> N;

	D[0] = D[1] = 1;
	for (int i=2; i<=N; ++i)
		for (int j=i-2; j>=0; --j)
			D[i] += D[j];

	cout << D[N] << endl;
	return 0;
}


