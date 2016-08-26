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

struct Rec {
	int y, x, yy, xx;
};

int N, M, K, Q, op[1000005][5];
vector<piii> G[2002];
vector<Rec> A;
ll fw[2002][2002], Data[2002][2002];
bool On[2002];

void update (int y, int x, ll v) {
	for (; y<=N; y+=y&-y)
		for (int t=x; t<=M; t+=t&-t)
			fw[y][t] += v;
}

ll query(int y, int x) {
	ll ret = 0;
	for (; y; y-=y&-y)
		for (int t=x; t; t-=t&-t)
			ret += fw[y][t];
	return ret;
}

int main () {
	scanf("%d%d%d", &N, &M, &K);

	for (int i=0; i<K; ++i) {
		int S;
		scanf("%d", &S);
		for (int j=0; j<S; ++j) {
			int t[3];
			for (int k=0; k<3; ++k)
				scanf("%d", t+k);
			G[i].push_back(make_pair(t[2], make_pair(t[0], t[1])));
		}
	}

	scanf("%d", &Q);
	for (int i=0; i<Q; ++i) {
		char t[10];
		scanf(" %s %d", t, &op[i][1]);
		if (t[0] == 'A') {
			op[i][0] = 1;
			for (int j=2; j<5; ++j) scanf("%d", &op[i][j]);
			A.push_back((Rec){op[i][1],op[i][2],op[i][3],op[i][4]});
		}
	}

	for (int i=0; i<K; ++i) {
		for (int j=0; j<G[i].size(); ++j)
			update(G[i][j].second.first, G[i][j].second.second, G[i][j].first);
		
		for (int j=0; j<A.size(); ++j) 
			Data[i][j] = query(A[j].yy, A[j].xx) - query(A[j].yy, A[j].x-1) - query(A[j].y-1, A[j].xx) + query(A[j].y-1, A[j].x-1);

		for (int j=0; j<G[i].size(); ++j)
			update(G[i][j].second.first, G[i][j].second.second, -G[i][j].first);
	}

	int cnt = 0;
	memset(On, true, sizeof(On));
	for (int i=0; i<Q; ++i) {
		if (op[i][0]) {
			ll sum = 0;
			for (int j=0; j<K; ++j) if (On[j])
				sum += Data[j][cnt];
			printf("%lld\n", sum);
			++cnt;
		}
		else
			On[op[i][1]-1] = !On[op[i][1]-1];
	}

	return 0;
}


