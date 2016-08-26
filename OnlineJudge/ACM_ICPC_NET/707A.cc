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
	int a, b;
	scanf("%d %d ", &a, &b);
	for (int i=0; i<a; ++i) for (int j=0; j<b; ++j) {
		char c;
		scanf(" %c", &c);
		if (c == 'C' || c == 'M' ||c == 'Y') {
			cout << "#Color" << endl;
			return 0;
		}
	}
	cout << "#Black&White" << endl;
	return 0;
}


