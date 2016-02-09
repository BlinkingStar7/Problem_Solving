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
	while(1) {
		vector<bool> sel(52,false);
		vector<int> princess, prince;
		for (int i=0; i<5; ++i) {
			int t;
			scanf("%d", &t);
			if (t == 0) return 0;
			sel[t] = true;
			if (i<3) princess.push_back(t);
			else prince.push_back(t);
		}
		
		int ans;
		for (ans=1; ans<=52; ++ans) {
			if (sel[ans]) continue;
			vector<int> t = prince;
			t.push_back(ans);
			sort(princess.begin(), princess.end());
			sort(t.begin(), t.end());

			vector<bool> c(3, false);
			int num=0;
			for (int i=2; i>=0; --i) {
				bool flag = false;
				for (int j=0; j<3; ++j) {
					if (!c[j] && princess[j] > t[i]) {
						c[j] = true;
						++num;
						flag = true;
						break;
					}
				}
				if (!flag) {
					for (int j=0; j<3; ++j)
						if (!c[j]) {
							c[j] = true;
							break;
						}
				}
			}
			if (num<=1) break;			

		}
		printf("%d\n", ans == 53 ? -1 : ans);
	}
	return 0;
}

