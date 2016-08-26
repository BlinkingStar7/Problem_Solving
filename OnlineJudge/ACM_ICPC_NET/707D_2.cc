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

const int MAX = 100005;
int N, M, Q, Real[MAX], Num[1001], op[MAX][3], V[MAX], cur;
bool B[1001][1001], S[1001];
vpii adj[MAX];

bool inc (int y, int x, int &n) {
	if (B[y][x] == S[y]) {
		B[y][x] = !B[y][x];
		++Num[y];
		++n;
		return true;
	}
	return false;
}


bool dec (int y, int x, int &n) {
	if (B[y][x] != S[y]) {
		B[y][x] = !B[y][x];
		--Num[y];
		--n;
		return true;
	}
	return false;
}

void tog (int y, int &n) {
	S[y] = !S[y];
	n += (M - Num[y]) - Num[y];
	Num[y] = M - Num[y];
}

void Solve(int cur, int num) {
	V[cur] = num;

	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i].second, opIndex = adj[cur][i].first;
		int y = op[opIndex][1], x = op[opIndex][2];
		bool f = true;
		switch(op[opIndex][0]) {
			case 1 : f = inc(y, x, num);
					 break;
			case 2 : f = dec(y, x, num);
					 break;
			case 3 : tog(y, num);
					 break;
		}

		Solve (next, num);

		if (f) {
			switch(op[opIndex][0]) {
				case 1 : dec(y, x, num);
						 break;
				case 2 : inc(y, x, num);
						 break;
				case 3 : tog(y, num);
						 break;
			}
		}
	}
}

int main () {
	scanf("%d%d%d", &N, &M, &Q);

	memset(V, -1, sizeof(V));
	for (int i=0; i<=Q; ++i)
		Real[i] = i;

	for (int i=0; i<Q; ++i) {
		for (int j=0; j<2; ++j) scanf("%d", &op[i][j]);
		if (op[i][0] == 1 || op[i][0] == 2) scanf("%d", &op[i][2]);
		
		if (op[i][0] == 4) 
			Real[i+1] = cur = Real[op[i][1]];
		else { 
			adj[cur].push_back(make_pair(i, i+1));
			cur = i+1;
		}
	}

	Solve(0, 0);
	
	for (int i=1; i<=Q; ++i) {
		if (V[i] == -1) V[i] = V[Real[i]];
		printf("%d\n", V[i]);
	}
	
	return 0;
}


