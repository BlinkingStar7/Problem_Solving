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

int n, next[300][2];

void preorder(char cur) {
	if (cur == '.') return;
	printf("%c",cur);
	preorder(next[cur][0]);
	preorder(next[cur][1]);
}
void postorder(char cur) {
	if (cur == '.') return;
	postorder(next[cur][0]);
	postorder(next[cur][1]);
	printf("%c",cur);
}
void inorder(char cur) {
	if (cur == '.') return;
	inorder(next[cur][0]);
	printf("%c",cur);
	inorder(next[cur][1]);
}
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		char root, ll, rr;
		scanf(" %c %c %c", &root, &ll, &rr);
		next[root][0] = ll;
		next[root][1] = rr;
	}

	preorder('A');
	puts("");
	inorder('A');
	puts("");
	postorder('A');
	puts("");
	return 0;
}


