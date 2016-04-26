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

const int MAX = 200001;
int n, m, base, IDT[1<<19], ans[MAX];
long long start[MAX], end[MAX];
bool v[MAX];
pair<long long, long long> key[MAX];
struct ss {
	long long first, second;
	int id;
	ss() {
		first = 1e18+1, second = 1e18+1, id = -1;
	}
	ss(long long f, long long s, int _id) : first(f), second(s), id(_id) {
	}
} seg[MAX];

void update(int t) {
	seg[t].second = INF;
	t += base;

	while (t>>=1) {
		IDT[t] = (seg[IDT[2*t]].second < seg[IDT[2*t+1]].second) ? IDT[2*t] : IDT[2*t+1];
	}
}

long long query(int a, int b) {
	long long ret = n-1;
	while (a < b) {
		if (a%2==1) { ret = seg[IDT[ret]].second > seg[IDT[a]].second ? IDT[a] : ret; ++a;}
		if (b%2==0) { ret = seg[IDT[ret]].second > seg[IDT[b]].second ? IDT[b] : ret; --b;}
		a>>=1, b>>=1;
	}
	if (a == b)
		ret = seg[IDT[ret]].second > seg[IDT[a]].second ? IDT[a] : ret;
	return ret;
}

bool cmp (const ss &a, const ss &b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}
	
int main () {
	scanf("%d%d", &n, &m);
	
	long long x, y;
	scanf("%lld%lld", &x, &y);
	
	for (int i=0; i<n-1; ++i) {
		long long xx, yy;
		scanf("%lld%lld", &xx, &yy);
		seg[i].first = xx-y;
		seg[i].second = yy-x;
		seg[i].id = i;
		x = xx, y = yy;
	}

	for (int i=0; i<m; ++i) {
		scanf("%lld", &key[i].first);
		key[i].second = i;
	}

	sort(key, key+m);
	sort(seg, seg+n-1, cmp);

	for (base=1; base<n-1; base<<=1)
		;

	for (int i=0; i<base; ++i) {
		if (i<n-1) IDT[base+i] = i;
		else IDT[base+i] = n-1;
	}
	if (base == n-1) IDT[base+n-1] = n-1;

	for (int i=base-1; i>0; --i)
		IDT[i] = (seg[IDT[2*i]].second < seg[IDT[2*i+1]].second) ? IDT[2*i] : IDT[2*i+1];
	
	int keyId = 0, check=0;
	for (int i=0; keyId<m && i<n-1; ++i, ++keyId) if (!v[i]) {
		long long keyVal = key[keyId].first;
		if (keyVal < seg[i].first) {
			--i;
		}
		else if (keyVal <= seg[i].second) {
			int bound = lower_bound(seg, seg+n-1, ss(keyVal+1, -INF, 0), cmp) - seg - 1;
			int q = query(base+i, base+bound);
			printf("query from %d to %d has %d\n", base+i, base+bound, q);
			printf("key %d accquried\n\n", keyId);
			update(q);
			v[q] = true;
			ans[seg[i].id] = key[keyId].second;
			++check;
			if (q != i) --i;
		}
	}
	if (check != n-1) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	for (int i=0; i<n-1; ++i)
		printf("%d%c", ans[i]+1, i == n-2 ? '\n' : ' ');

	return 0;
}


