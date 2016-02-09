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

int main () {
	long long N, ans = 1;
	cin >> N;

	long long sqrtN = sqrt(N);
	for (int p=2; p<=sqrtN; ++p) {
		if (N%p == 0) ans *= p;
		while(N%p == 0) N/=p;
	}
	if (N != 1) ans *= N;

	cout << ans << endl;
	return 0;
}

