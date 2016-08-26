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

int N, M, Q, Book[1001], op[1001][3], V[1001];
bool B[1001][1001], S[1001];
vpii adj[1001];

inline void toggle(int i, int &n) {
	S[i] = !S[i];
	n += (M-Book[i]) - Book[i];
	Book[i] = M - Book[i];
}

inline void inc(int i, int j, int &n) {
	if (B[i][j] == S[i]) {
		B[i][j] = !B[i][j];
		Book[i]++;
		n++;
	}
}

inline void dec(int i, int j, int &n) {
	if (B[i][j] != S[i]) {
		B[i][j] = !B[i][j];
		Book[i]--;
		n--;
	}
}

void Solve(int cur, int num) {
	V[cur] = num;

	for (int i=0; i<adj[cur].size(); ++i) {
		int opp = adj[cur][i].first;
		int next = adj[cur][i].second;
		int x = op[opp][2], y = op[opp][1];
		switch(op[opp][0]) {
			case 1 : inc(y, x, num);
					 break;
			case 2 : dec(y, x, num);
					 break;
			case 3 : toggle(y, num);
					 break;
		}

		Solve(next, num);

		switch(op[opp][0]) {
			case 1 : dec(y, x, num);
					 break;
			case 2 : inc(y, x, num);
					 break;
			case 3 : toggle(y, num);
					 break;
		}
	}
}

int main () {
	scanf("%d%d%d", &N, &M, &Q);

	int bef = 0;
	for (int i=0; i<=Q; ++i)
		real[i] = i;
	for (int i=0; i<Q; ++i) {
		scanf("%d%d", &op[i][0], &op[i][1]);
		if (op[i][0] == 1 || op[i][0] == 2)
			scanf("%d", &op[i][2]);
		if (op[i][0] == 4) bef = op[i][1];
		else { 
			adj[bef].push_back(make_pair(i, i+1));
			bef = i+1;
		}
	}

	memset(V, -1, sizeof(V));
	Solve(0, 0);

	for (int i=1; i<=Q; ++i) {
		if (V[i] == -1) {
			V[i] = V[op[i-1][1]];
		}
		printf("%d\n", V[i]);
	}

	return 0;
}


