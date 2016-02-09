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
	int n, sToi[10001], iTos[10001];
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int s;
		scanf("%d", &s);
		sToi[s] = i;
		iTos[i] = s;
	}

	int seq[10001];
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		seq[sToi[t]] = i;
	}

	int greedy[10001], len[10001], size=0;
	for (int i=0; i<n; ++i) {
		int pos = lower_bound(greedy, greedy+size, seq[i])-greedy;
		greedy[pos] = seq[i];
		if (pos == size) ++size;
		len[i] = pos;
	}

	printf("%d\n", size);
	vi ans;
	for (int i=n-1; i>=0 && size; --i) {
		if (len[i] == size-1) {
			ans.push_back(iTos[i]);
			--size;
		}
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<(int)ans.size(); ++i)
		printf("%d ", ans[i]);

	return 0;
}


