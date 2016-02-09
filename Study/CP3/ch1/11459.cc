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
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif


int main () {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a, b, c;
		vector<int> ladder(101, 0);
		scanf("%d%d%d",&a,&b,&c);
		for (int i=0; i<b; ++i) {
			int x, y;
			scanf("%d%d",&x,&y);
			ladder[x] = y;
		}
		vector<int> pos(a, 1);
		int player = 0;
		bool flag = false;
		for (int i=0; i<c; ++i, player = (player+1)%a) {
			int d;
			scanf("%d", &d);
			if (flag) continue;
			pos[player] = min(100, pos[player] + d);
			if (ladder[pos[player]])
				pos[player] = ladder[pos[player]];
			if (pos[player] == 100) flag = true;
		}

		for (int i=0; i<a; ++i)
			printf("Position of player %d is %d.\n",i+1, pos[i]);
	}

	return 0;
}

