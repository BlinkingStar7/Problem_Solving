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

int n, a[101], visited[101];
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", a+i);

	int counter = 1;
	vi ans;
	for (int i=1; i<=n; ++i) {
		if (visited[i]) continue;

		int cur = i, len = 0, start = -1;
		while(1) {
			visited[cur] = counter;
			int next = a[cur];
			if (visited[next]) {
				if (visited[next] == counter) {start = cur; break; }
				else break;
			}
			cur = next;
		}

		if (start != -1) {
			ans.push_back(start);
			cur = a[start];
			while (cur != start) {
				ans.push_back(cur);
				cur = a[cur];
			}
		}
		++counter;
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);
	return 0;
}


