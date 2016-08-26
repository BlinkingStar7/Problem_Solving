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
	vi a;
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		int t; 
		scanf("%d", &t);
		a.push_back(t);
	}

	stack<int> aa, bb;
	for (int i=n-1; i>=0; --i)
		aa.push(a[i]);

	int cur = 1;
	while (1) {
		if (!aa.empty() && aa.top() == cur) {
			aa.pop();
			++cur;
		}
		else if (!bb.empty() && bb.top() == cur) {
			bb.pop();
			++cur;
		}
		else if (!aa.empty()) {
			bb.push(aa.top());
			aa.pop();
		}
		else break;
	}

	printf("%s\n", cur == n+1 ? "Nice" : "Sad");
	return 0;
}


