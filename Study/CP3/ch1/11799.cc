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
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;


int main () {
	int n;
	cin >> n;
	for (int i=1; i<=n; ++i) {
		int num;
		cin >> num;
		int ans = 0;
		for (int j=0; j<num; ++j) {
			int t;
			cin >> t;
			ans = max (ans, t);
		}
		printf("Case %d: %d\n", i, ans);
	}

	return 0;
}

