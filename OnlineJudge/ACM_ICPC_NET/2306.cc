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

string s;
int memo[501][501];
int solve(int a, int b) {
	if (a >= b) return 0;

	int &ret = memo[a][b];
	if (ret != -1) return ret;

	if (s[a] == 't' || s[a] == 'c') return ret = solve(a+1, b);
	if (s[b] == 'a' || s[b] == 'g') return ret = solve(a, b-1);
	ret = 0;
	char toFind = s[a] == 'a' ? 't' : 'c';

	for (int nb=b; nb>a; --nb)
		if(s[nb] == toFind) {
			ret = max(ret, 2+solve(a+1, nb-1)+solve(nb+1, b));
		}

	
	toFind = s[b] == 't' ? 'a' : 'g';
	for (int na=a; na<b; ++na)
		if (s[na] == toFind) {
			ret = max(ret, 2+solve(a, na-1)+solve(na+1,b-1));
		}


	return ret;
}

int main () {
	cin >> s;
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0,s.size()-1));
	return 0;
}


