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

string A, B;
int n;

vi pp() {
	vi ret, back(n+1, 0); back[0] = -1;
	int i=0, j=-1;

	while (i<=n) {
		while (j>=0 && A[i] != A[j]) j = back[j];
		++i, ++j;
		back[i] = j;
	}

	int cur = n;
	while (cur != 0) {
		ret.push_back(cur);
		cur = back[cur];
	}
	return ret;
}

int main () {
	cin >> A >> B;
	A += B;
	n = A.size();

	vi ret = pp();
	for (int i=ret.size()-1; i>=0; --i)
		printf("%d ", ret[i]);

	return 0;
}


