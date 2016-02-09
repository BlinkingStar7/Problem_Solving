#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;


int N, Num[1001];

pair<int, int> Compute (int a, int b) {
	int strike=0, ball=0;
	string A=to_string(a), B=to_string(b);

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			if (A[i] == B[j]) {
				if (i==j) ++strike;
				else ++ball;
			}
	return make_pair(strike, ball);
}

int main () {
	for (int i=111; i<=999; ++i) {
		int a = i/100, b=(i/10)%10, c=i%10;
		if (a != 0 && b != 0 && c!= 0 && a != b && b != c && c != a)
			Num[i] = 1;
	}

	cin >> N;
	for (int i=0; i<N; ++i) {
		int cur, s, b;
		cin >> cur >> s >> b;
		pair<int, int> p = make_pair(s, b);
		for (int j=111; j<=999; ++j)
			if (Num[j]) {
				if (Compute(cur, j) != p) Num[j] = 0;
			}
	}

	int ans=0;
	for (int i=111; i<=999; ++i)
		ans += Num[i];

	cout << ans << endl;


	


	return 0;
}

