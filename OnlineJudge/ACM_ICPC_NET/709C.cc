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

char A[100005];
int a;
int main () {
	gets(A);
	a = strlen(A);

	bool flag = false;
	for (int i=0; i<a; ++i) {
		if (!flag && A[i] != 'a') {
			flag = true;
			A[i] -= 1;
		}
		else if (flag && A[i] == 'a') break;
		else if (flag) {
			A[i] -= 1;
		}
	}
	if (!flag) {
		A[a-1] = 'z';
	}
	printf("%s\n", A);

	return 0;
}


