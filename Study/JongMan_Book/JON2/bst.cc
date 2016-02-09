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

int main () {
	cin >> testNum;

	map<int, int> m;
	while (testNum--) {
		int a, b;
		cin >> a >> b;
		m[a] = b;
	}

	cout << m.lower_bound(3)->first << endl;


	return 0;
}

