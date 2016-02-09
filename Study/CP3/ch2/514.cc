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
#include <bitset>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;

		while (1) {
			int head = 1;
			bool end = false, ans = true;
			stack<int> s;
			for (int i=0; i<n; ++i) {
				int t;
				scanf("%d", &t);
				if (t == 0) { end = true; break;}
				if (t == head) ++head;
				else if (t < head) {
					if (s.top() != t) ans = false;
					else s.pop();
				}
				else {
					while(head <= t) 
						s.push(head++);
					s.pop();
				}
			}
			if (end) break;

			printf("%s\n", ans ? "Yes" : "No");
		}
		puts("");
	}
	return 0;
}

