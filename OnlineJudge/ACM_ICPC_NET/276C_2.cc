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

const int MAX = 200002;
int N, Q, Arr[MAX], Fw[MAX], Arr2[MAX];

void update (int p, int v) {
	while (p <= N) {
		Fw[p] += v;
		p += p & -p;
	}
}

int read (int p) {
	int ret = 0;
	while (p) {
		ret += Fw[p];
		p -= p & -p;
	}
	return ret;
}

int main () {
	cin >> N >> Q;

	for (int i=0; i<N; ++i)
		scanf("%d", Arr+i);

	for (int i=0; i<Q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		update(a, 1);
		update(b+1, -1);
	}

	for (int i=0; i<N; ++i)
		Arr2[i] = read(i+1);

	sort(Arr, Arr+N);
	sort(Arr2, Arr2+N);

	ll ans = 0;
	for (int i=0; i<N; ++i)
		ans += (ll)Arr[i] * Arr2[i];

	cout << ans << endl;

	return 0;
}


