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

int N;
int main () {
	cin >> N;
	int m=1, prev, asc = 1, des = 1;
	scanf("%d", &prev);
	for (int i=1; i<N; ++i) {
		int x;
		scanf("%d", &x);
		if (x > prev) {
			des = 1;
			++asc;
		}
		else if (x < prev) {
			asc = 1;
			++des;
		}
		else {
			++asc;
			++des;
		}
		int cand = max(asc, des);
		m = max (m, cand);
		prev = x;
	}
	cout << m << endl;

	return 0;
}

