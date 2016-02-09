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

const int INF = 1e8;
int main () {
	int n,b,h,w;
	while(scanf("%d%d%d%d",&n,&b,&h,&w) != EOF) {
		int ans = INF;
		for (int i=0; i<h; ++i) {
			int per;
			cin >> per;
			for (int j=0; j<w; ++j) {
				int acc;
				cin >> acc;
				if (acc >= n) ans = min(ans, per*n);
			}
		}
		if (ans > b) cout << "stay home" << endl;
		else cout << ans << endl;

	}
	return 0;
}

