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
	int n;
	cin >> n;
	for (int i=1; i<=n; ++i) {
		vector<int> v(3);
		for (int j=0; j<3; ++j)
			scanf("%d",&v[j]);
		sort(v.begin(), v.end());
		printf("Case %d: %d\n", i,v[1]);
	}
	return 0;
}

