#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *r, *d;
} B[1005][1005];

int N, M, Q;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M >> Q;

	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> B[i+1][j+1].val;
	for (int i=0; i<N; ++i) for (int j=0; j<=M; ++j)B[i][j].d = &B[i+1][j];
	for (int i=0; i<=N; ++i) for (int j=0; j<M; ++j)B[i][j].r = &B[i][j+1];
	
	for (int i=0; i<Q; ++i) {
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;
		Node *x = &B[0][0], *y = &B[0][0];

		while (--a) x = x->d;
		while (--b) x = x->r;
		while (--c) y = y->d;
		while (--d) y = y->r;

		Node *u = x, *v = y;
		for (int i=0; i<h; ++i) {
			u = u->d;
			v = v->d;
			swap(u->r, v->r);
		}
		
		for (int i=0; i<w; ++i) {
			u = u->r;
			v = v->r;
			swap(u->d, v->d);
		}

		for (int i=0; i<w; ++i) {
			x = x->r;
			y = y->r;
			swap(x->d, y->d);
		}

		for (int i=0; i<h; ++i) {
			x = x->d;
			y = y->d;
			swap(x->r, y->r);
		}
	}

	Node *r = (&B[0][0])->r->d, *c;
	int i , j;
	for (i=1, r = (&B[0][0])->r->d; i<=N; ++i, r = r->d) {
		for (j=1, c = r; j<=M; ++j, c = c->r) {
			printf("%d%c", c->val, j == M ? '\n' : ' ');
		}
	}

	return 0;
}
	

