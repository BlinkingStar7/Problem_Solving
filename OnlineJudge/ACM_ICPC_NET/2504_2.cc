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

inline bool safe (char a, char b) {
	if (a == '(') return b == ')';
	if (a == '[') return b == ']';
}

int main () {
	char input[33];
	scanf("%s", input);
	int n = strlen(input);

	int cur = 1, ans = 0;
	bool flag = false;
	stack<char> st;
	for (int i=0; i<n; ++i) {
		char c = input[i];
		if (c == '(' || c == '[') { cur *= (c == '(' ? 2 : 3); st.push(c); flag = true;}
		else {
			if (st.empty() || !safe(st.top(), c)) { return printf("0\n"), 0; }
			if (flag) { flag = false; ans += cur; }
			cur /= (c == ')' ? 2 : 3);
			st.pop();
		}
	}
	if (!st.empty()) ans = 0;
	printf("%d\n", ans);
	return 0;
}


