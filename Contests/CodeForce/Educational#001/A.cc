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

int testNum;
long long N;

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		long long sum = N*(N+1)/2;
		long long b = 1;
		while (b <= N) {
			sum -= 2*b;
			b<<=1;
		}

		cout << sum << endl;
	}


	return 0;
}

