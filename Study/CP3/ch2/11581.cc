#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int ans[1<<9];
inline bool isSafe(int y, int x) {
	return y>=0&&x>=0&&y<3&&x<3;
}

const int dy[4] = {-1,0,1,0}, dx[4]={0,1,0,-1};
void dfs(vi& list, vb  & sel, int cur) {
	if (sel[cur]) {
		vi::iterator start = find(list.begin(), list.end(), cur), it;
		int cnt = start - list.begin() - 1;
		for (it=list.begin(); it!=start; ++it)
			ans[*it] = cnt--;
		for (it=start; it!=list.end(); ++it)
			ans[*it] = INF;
		return;
	}
	
	int here[3][3], next = 0;
	int cnt = 8;
	for (int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) 
			here[i][j] = cur&(1<<(cnt--));

	for (int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			int num=0;
			for(int d=0; d<4; ++d) {
				int ny=i+dy[d], nx=j+dx[d];
				if (isSafe(ny, nx) && here[ny][nx]) ++num;
			}
			next = (next<<1) | (num%2);
		}

	list.push_back(cur);
	sel[cur] = true;
	
	if (ans[next] == -1) {
		return dfs(list, sel, next);
	}
	
	int val = ans[next] == INF ? 0 : ans[next] + 1;
	for (int i=list.size()-1; i>=0; --i)
		ans[list[i]] = val++;
}

void init() {
	memset(ans, -1, sizeof(ans));
	for(int i=0; i<1<<9; ++i) {
		if (ans[i] == -1) {
			vi list;
			vb select(1<<9, false);
			dfs(list, select, i);
		}
	}
}

int main () {
	int t;
	cin >> t;
	init();
	while(t--) {
		int board = 0;
		for (int i=0; i<9; ++i) {
			int t;
			scanf("%1d", &t);
			board = (board<<1) | t;
		}

		printf("%d\n", ans[board] == INF ? -1 : ans[board]);
	}			

	return 0;
}

