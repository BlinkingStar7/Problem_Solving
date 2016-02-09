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

struct President {
	int num, total, three, two;
};

bool compare(const President &a, const President &b) {
	if (a.total != b.total) return a.total > b.total;
	if (a.three != b.three) return a.three > b.three;
	if (a.two != b.two) return a.two > b.two;
	return false;
}



int main () {
	President p[3] = {{1,0,0,0},{2,0,0,0},{3,0,0,0}};
	int n;
	cin >> n;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			int x;
			scanf("%d", &x);
			p[j].total += x;
			if (x == 3) p[j].three++;
			if (x == 2) p[j].two++;
		}
	}

	sort (p, p+3, compare);

	if (!compare(p[0], p[1]) && !compare(p[1], p[0]))
		cout << 0 << " " << p[0].total <<  endl;
	else 
		cout << p[0].num << " " << p[0].total << endl;


	return 0;
}

