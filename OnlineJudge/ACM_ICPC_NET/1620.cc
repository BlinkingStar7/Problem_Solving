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

int n, m;
string str[100001];
map<string, int> mmap;
int main () {
	scanf("%d%d ", &n, &m);
	for (int i=0; i<n; ++i) {
		cin >> str[i+1];
		mmap[str[i+1]] = i+1;
	}
	
	for (int i=0; i<m; ++i) {
		string s;
		cin >> s;
		if (isdigit(s[0])) cout << str[atoi(s.c_str())] << endl;
		else cout << mmap[s] << endl;
	}

	return 0;
}


