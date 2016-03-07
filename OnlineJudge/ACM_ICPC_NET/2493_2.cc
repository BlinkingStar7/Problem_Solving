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
	int n, a[500001];
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", a+i);
	a[0] = 123123123;

	stack<int> st; st.push(0);
	for (int i=1; i<=n; ++i) {
		while (a[st.top()] < a[i])
			st.pop();
		
		printf("%d ", st.top());
		st.push(i);
	}
	
	return 0;
}


