#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	char input[20];
	int reg, p;
	priority_queue<piii> pq;
	while(scanf("%s", input)) {
		if (input[0] == '#') break;
		scanf("%d%d ",&reg, &p);
		pq.push(make_pair(-p, make_pair(-reg, p)));
	}
	int k;
	scanf("%d", &k);
	for (int i=0; i<k; ++i) {
		piii pair = pq.top();
		pq.pop();
		printf("%d\n", -pair.second.first);
		pair.first -= pair.second.second;
		pq.push(pair);
	}
		

	return 0;
}

