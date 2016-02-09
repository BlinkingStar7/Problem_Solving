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
	int N, cur = 0, ans = -987654321;
	cin >> N;
	while (N--) {
		int t;
		scanf("%d",&t);
		cur = cur<0?t:cur+t;
		ans = max(ans, cur);
	}
	cout << ans << endl;
		


	return 0;
}

