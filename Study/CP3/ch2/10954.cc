#include <bits/stdc++.h>
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
	while (scanf("%d", &n) && n) {
		priority_queue<int,vector<int>, greater<int> > pq;
		for (int i=0; i<n; ++i) {
			int temp;
			scanf("%d",&temp);
			pq.push(temp);
		}

		long long ans = 0;
		for (int i=0; i<n-1; ++i) {
			long long temp = pq.top(); pq.pop();
			temp += pq.top(); pq.pop();
			ans += temp;
			pq.push(temp);
		}
		printf("%lld\n", ans);
	}


		
	return 0;
}

