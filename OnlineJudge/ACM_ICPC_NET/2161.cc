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

int main () {
	int n;
	queue<int> q;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		q.push(i+1);

	while (q.size() != 1) {
		printf("%d ", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	
	printf("%d\n", q.front());
	return 0;
}


