#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int n, k, bef = -1, num[21] = {}, ans = 0;
	scanf("%d%d", &n, &k);
	stack<int> st;

	for (int i=0; i<n; ++i) {
		int cur; scanf("%d", &cur);
		if (bef != cur) {
			if (num[cur]) {
				while(st.top() != cur) {
					--num[st.top()];
					st.pop();
					++ans;
				}
			}
			else {
				++num[cur];
				st.push(cur);
			}
			bef = cur;
		}
	}

	ans += st.size() - 1;
	printf("%d\n", ans);
	return 0;
}


