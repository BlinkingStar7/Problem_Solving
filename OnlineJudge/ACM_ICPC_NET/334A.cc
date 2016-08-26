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

int A[101][101];
int main () {
	int n;
	scanf("%d", &n);
	
	int cnt = 1;
	for (int j=0; j<n; ++j) {
		if (j%2 == 0) 
			for (int i=0; i<n; ++i) 
				A[i][j] = cnt++;
		else
			for (int i=n-1; i>=0; --i)
				A[i][j] = cnt++;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) 
			printf("%d%c", A[i][j], j==n-1 ? '\n': ' ');



	return 0;
}


