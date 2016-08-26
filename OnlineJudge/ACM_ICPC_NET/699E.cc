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

int N, K;
double P[25], M[25][25], A[25][25];

void mul (double A[][25], double B[][25]) {
	double C[25][25] = {0, };
	for (int i=0; i<=K; ++i)
		for (int j=0; j<=K; ++j) 
			for (int k=0; k<=K; ++k) 
				C[i][j] += A[i][k] * B[k][j];
	memcpy (A, C, sizeof(C));
}

int main () {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; ++i)
		scanf("%lf", P+i);

	for (int c=0; c<N; ++c) {
		memset(M, 0, sizeof(M));
		memset(A, 0, sizeof(A));
		for (int i=0; i<=K; ++i) {
			M[i][1] = P[c];
			M[i][i==0 ? 0 : (i+1)%(K+1)] = 1-P[c];
			A[i][i] = 1;
		}
		
		int cnt = INF;
		vi v;
		while (cnt) {
			v.push_back(cnt%2);
			cnt>>=1;
		}

		for (int i=v.size()-1; i>=0; --i) {
			mul(A, A);
			if (v[i]) mul(A, M);
		}

		for (int i=0; i<=K; ++i) for (int j=0; j<=K; ++j)
			printf("%lf%c", A[i][j], j == K ? '\n' : ' ');
	}
		

	return 0;
}


