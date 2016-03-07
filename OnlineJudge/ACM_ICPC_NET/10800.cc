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

#define MAX 200001
struct ball {
	int color, size, index;
} b[MAX];

bool comp1 (const ball &a, const ball &b) {
	return a.size != b.size ? a.size < b.size : a.color < b.color;
}

bool comp2 (const ball &a, const int &b) {
	return a.size < b;
}

int n, ans[MAX], psum[MAX], bef[MAX];
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d%d", &b[i].color, &b[i].size);
		b[i].index = i;
	}

	sort(b+1, b+n+1, comp1);
	for (int i=1; i<=n; ++i)
		psum[i] += psum[i-1] + b[i].size;

	for (int i=1; i<=n; ++i) {
		int index = b[i].index, c = b[i].color, s = b[i].size;
		int pos = lower_bound(b+1, b+1+n, s, comp2) - b;
		int temp = psum[pos-1] - bef[c];
	
		int sum = 0, j;
		for (j=i; j<=n && b[j].color == b[i].color && b[j].size == b[i].size; ++j) {
			int cur = b[j].index;
			ans[cur] = temp;
			sum += b[j].size;
		}
		i = j-1;
		bef[c] += sum;
	}

	for (int i=1; i<=n; ++i)
		printf("%d\n", ans[i]);

	return 0;
}


