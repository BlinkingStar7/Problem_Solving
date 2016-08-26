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

const int MAX = 1000005;
int N, Q, A[MAX], XOR[MAX], TOT[MAX], EXC[MAX];
bool V[MAX];
set<int> S;

int main () {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i) {
		scanf("%d", A+i);
		XOR[i] = XOR[i-1]^A[i];
		TOT[i] = TOT[i-1];
		if (S.find(A[i]) == S.end()) {
			S.insert(A[i]);
			TOT[i] ^= A[i];
		}
	}

	S.clear();

	for (int i=N; i>0; --i) {
		if (S.find(A[i]) == S.end()) {
			V[i] = true;
			S.insert(A[i]);
		}
	}

	for (int i=1; i<=N; ++i) {
		EXC[i] ^= EXC[i-1];
		if (V[i]) EXC[i+1] = A[i];
	}
	
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", TOT[r] ^ EXC[l] ^ XOR[r] ^ XOR[l-1]);
	}
	return 0;
}


