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

vector<pair<int, string> > stu[10001];

int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		string name;
		int region, score;
		cin >> name >> region >> score;
		stu[region].push_back(make_pair(score, name));
	}
	for (int i=1; i<=m; ++i) {
		sort(stu[i].begin(), stu[i].end(), greater<pair<int, string> >());
		if (stu[i].size() == 2 || stu[i][1].first != stu[i][2].first) {
			cout << stu[i][0].second << ' ' << stu[i][1].second << endl;
		}
		else
			printf("?\n");
	}
	return 0;
}


