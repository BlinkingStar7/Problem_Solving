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

int main () {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;

	for (int i=0; i<N; ++i) {
		cin >> Size[i];
		for (int j=0; j<Size[i]; ++j) for (int k=0; k<3; ++k)
			cin >> Light[i][j][k];
	}

	cin >> Q;
	for (int i=0; i<Q; ++i) {
		string s;
		cin >> s;
		Operation[i][0] = s[0] == 'A';
		for (int j=1; j < s[0] == 'A' ? 5 : 2; ++j) 
			cin >> Operation[i][j];
	}

	for (int g=0; g<N; ++g) {
		for (int i=0; i<Size[i]; ++i)
			update(Light[g][i][0], Light[g][i][1]

	return 0;
}


