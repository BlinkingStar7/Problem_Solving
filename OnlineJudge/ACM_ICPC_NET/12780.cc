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
	string A, B;
	cin >> A >> B;

	int cnt = 0;
	for (int i=0; i<A.size()-B.size()+1; ++i) {
		bool flag = true;
		for (int j=0; j<B.size(); ++j)
			if (A[i+j] != B[j]) {
				flag = false;
				break;
			}
		if (flag) ++cnt;
	}

	printf("%d\n", cnt);

	return 0;
}


