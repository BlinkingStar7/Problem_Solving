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
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 200001;
int N, Q, Arr[MAX], Seg[MAX<<2], Lazy[MAX<<2];

void update (int x, int y, int xx, int yy, int node) {
	if (x >= xx && y <= yy) Lazy[node] += 1;

	if (Lazy[node]) {
		Seg[node] += (y-x+1)*Lazy[node];
		if (x != y) {
			Lazy[node*2] += Lazy[node];
			Lazy[node*2+1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	if (y < xx || x > yy) return;
	if (x >= xx && y <= yy) return;

	update(x, (x+y)/2, xx, yy, node*2);
	update((x+y)/2+1, y, xx, yy, node*2+1);
	Seg[node] = Seg[node*2] + Seg[node*2+1];
}

int query (int x, int y, int xx, int yy, int node) {
	if (Lazy[node]) {
		Seg[node] += (y-x+1)*Lazy[node];
		if (x != y) {
			Lazy[node*2] += Lazy[node];
			Lazy[node*2+1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	int mid = (x+y)/2;
	if (y < xx || x > yy) return 0;
	if (x >= xx && y <= yy) return Seg[node];
	return query(x, mid, xx, yy, node*2) + query(mid+1, y, xx, yy, node*2+1);
}

int main () {
	scanf("%d%d", &N, &Q);

	for (int i=0; i<N; ++i)
		scanf("%d", Arr+i);

	for (int i=0; i<Q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		update(0, N-1, a-1, b-1, 1);
	}

	vi vec;
	for (int i=0; i<N; ++i)
		vec.push_back(query(0, N-1, i, i, 1));

	sort(vec.begin(), vec.end(), greater<int>());
	sort(Arr, Arr+N, greater<int>());

	ll ans = 0;
	for (int i=0; i<N; ++i)
		ans += (ll)vec[i] * Arr[i];

	cout << ans << endl;

	return 0;
}


