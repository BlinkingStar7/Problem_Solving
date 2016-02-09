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

int main () {
	int x, m=101, s=0;
	for (int i=0; i<7; ++i) {
		scanf("%d", &x);
		if (x%2) {
			s += x;
			if (x < m)
				m = x;
		}
	}
	if (s == 0) {
		cout << -1 << endl;
	}
	else {
		cout << s << endl << m << endl;
	}
	
	return 0;
}

