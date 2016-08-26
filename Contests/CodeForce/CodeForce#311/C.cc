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

int n, ssum; 
pii a[104856];

class cmp {
	public:
	bool operator() (int x, int y) {
		return a[x].second > a[y].second;
	}
};

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i].first);
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i].second);
		ssum += a[i].second;
	}
	
	sort(a, a+n);

	vector<int> v;
	priority_queue<int, vi, cmp> q;
	int cur = a[0].first, sum = 0, num = 0, ans = 0;

	for (int i=0; i<n; ++i) {
		if (a[i].first == cur) {
			sum += a[i].second;
			v.push_back(i);
			++num;
		}
		else {
			while (num < (q.size() + num)/2 + 1) {
				int t = q.top(); q.pop();
				sum -= a[t].second;
			}
			ans = max(ans, sum);
			for (int j=0; j<v.size(); ++j)
				q.push(v[j]);
			v.clear();

			v.push_back(i);
			sum += a[i].second;
			num = 1;
			cur = a[i].first;
		}
	}

	while (num < (q.size() + num)/2 + 1) {
		int t = q.top(); q.pop();
		sum -= a[t].second;
	}
	ans = max(ans, sum);

	printf("%d\n", ssum - ans);
	return 0;
}


