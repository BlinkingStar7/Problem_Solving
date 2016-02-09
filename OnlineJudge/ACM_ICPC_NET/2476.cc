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
	int Max=0;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a[3], cand=0;
		for (int j=0; j<3; ++j)
			scanf("%d", a+j);
		sort(a, a+3);
		if (a[0] == a[2])
			cand = 10000 + a[2]*1000;
		else if (a[0] == a[1] || a[1] == a[2])
			cand = 1000 + a[1]*100;
		else
			cand = a[2]*100;
		if (cand > Max)
			Max = cand;
	}
	cout << Max << endl;


	return 0;
}

