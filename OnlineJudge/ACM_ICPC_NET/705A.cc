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
	int n;
	scanf("%d", &n);
	
	for (int i=0; i<n; ++i) {
		if (i) printf("that ");
		if (i%2) printf("I love ");
		else printf("I hate ");
	}
	printf("it\n");

	return 0;
}


