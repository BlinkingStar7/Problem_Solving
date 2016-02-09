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

#define MAX 500001
struct abc { int x,y; 
	bool operator < (const abc& rhs) const { return x != rhs.x ? x < rhs.x : y > rhs.y; } 
	bool operator == (const abc& rhs) const { return x == rhs.x && y == rhs.y; }
} A[MAX];
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		scanf("%*d%d%d", &A[i].x, &A[i].y);
	sort(A, A+n);
	n = unique(A, A+n) - A;
	
	int greedy[MAX], real[MAX], size=0;
	for (int i=0; i<n; ++i) {
		int* pos = upper_bound(greedy, greedy+size, A[i].y, greater<int>());
		*pos = A[i].y;
		if (pos == greedy + size)
			++size;
	}
	printf("%d\n", size);
	return 0;
}


