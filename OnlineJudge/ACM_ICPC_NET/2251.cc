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


int vv[3];
bool v[201][201][201], ans[201];
int main () {
	for (int i=0; i<3; ++i) scanf("%d", vv+i);
	v[0][0][vv[2]] = true;
	queue<vi> q;
	vi temp = {0, 0, vv[2]}; q.push(temp);
	ans[vv[2]] = true;

	while(!q.empty()) {
		vi cur = q.front(); q.pop();

		for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) if (i != j) {
			vi temp = cur;
			int pour = min(temp[i], vv[j] - temp[j]);
			temp[i] -= pour; temp[j] += pour;
			if (!v[temp[0]][temp[1]][temp[2]]) {
				v[temp[0]][temp[1]][temp[2]] = true;
				if (temp[0] == 0) ans[temp[2]] = true;
				q.push(temp);				
			}
		}
	}

	for (int i=0; i<=vv[2]; ++i)
		if (ans[i]) printf("%d%c", i, i==vv[2] ? '\n' : ' ');
	return 0;
}


