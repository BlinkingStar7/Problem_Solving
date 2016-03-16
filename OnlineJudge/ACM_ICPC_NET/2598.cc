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

int solve (vi &sel, int cur, int top) {
	if (cur == 4) {
		vs col(4);
		for (int i=0; i<4; ++i)
			col[i] = getCol(sel[i]);
		bool ans = true;
		for (int box=0; box<4; ++box) {


int main () {
	for (int i=0; i<4; ++i) {
		for (int j=0; j<6; ++j) 
		getchar();
	}

	for (int top=0; top<4; ++top) 
		vi sel(4);

	printf("%d\n", ans);
	return 0;
}


