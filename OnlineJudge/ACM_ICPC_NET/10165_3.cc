#include <cstdio>
#include <algorithm>
using namespace std;

struct vv {
	int a, b, in;
	bool operator < (const vv x) const { return a != x.a ? a < x.a : b > x.b; }
} v[500001];
int n, m, over; bool ans[500001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &v[i].a, &v[i].b);
		v[i].in = i+1;
		if (v[i].a > v[i].b) {
			over = max(over, v[i].b);
			v[i].b += n;
		}
	}

	sort(v, v+m);
	for (int i=0; i<m; ++i)
		if (v[i].b > over) { ans[v[i].in] = true; over = v[i].b; }

	for (int i=1; i<=m; ++i)
		if (ans[i]) printf("%d ",i);
	return 0;
}
