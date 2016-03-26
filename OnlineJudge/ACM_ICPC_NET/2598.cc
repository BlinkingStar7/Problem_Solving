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

const int face[6][5] = {
	{1, 5, 3, 4, 2},
	{0, 4, 2, 5, 3},
	{4, 1, 5, 3, 0},
	{4, 0, 5, 2, 1},
	{0, 3, 2, 1, 5},
	{0, 1, 2, 3, 4}};

int cube[4][6], ans, mm[300];
pii record[4];
map<vector<int>, int> m[4];

void solve(int cur) {
	if (cur == 4) {
		bool check[4][4] = {};
		vi e(4);
		for (int s=0; s<4; ++s) {
			int encode = 0;
			for (int c=0; c<4; ++c, encode<<=2) {
				int bot = record[c].first, rot = (s+record[c].second)%4;
				int color = cube[c][face[bot][rot]];
				DPRINTF(("cube%d : bot %d rot %d color %d\n", c, bot, rot, color));
				encode |= color;
				if (check[s][color]) return;
				check[s][color] = true;
			}
			e[s] = encode;
		}
		int top = cube[3][face[ record[3].first ][4]];
		for (int i=0; i<4; ++i) {
			if (m[top].find(e) != m[top].end()) return;
			e.push_back(e[0]);
			e.erase(e.begin());
		}
		DPRINTF(("%d SUCC\n", top));

		m[top][e];
		++ans;
		return;
	}

	for (int bot=0; bot<6; ++bot)
		for (int rot=0; rot<4; ++rot) {
			record[cur] = make_pair(bot, rot);
			solve(cur+1);
		}
}

int main () {
	mm['R'] = 0, mm['G'] = 1, mm['B'] = 2, mm['Y'] = 3;
	for (int i=0; i<4; ++i) {
		for (int j=0; j<6; ++j) {
			char c; scanf("%c", &c);
			cube[i][j] = mm[c];
		}
		getchar();
	}

	solve(0);

	printf("%d\n", ans);
	return 0;
}


