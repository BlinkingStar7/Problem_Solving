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

int V, toInt[300], in[30];
vi adj[30];
string nodes;

bool dfs(vb &visited, vi &selected) {

	if (selected.size() == V) {
		for (int i=0; i<(int)selected.size()-1; ++i)
			printf("%c ", nodes[selected[i]]);
		printf("%c\n", nodes[selected.back()]);
		return true;
	}

	bool ret = false;
	for (int next=0; next<V; ++next) {
		if (visited[next] || in[next] != 0) continue;
		visited[next] = true;
		selected.push_back(next);
		for (int j=0; j<(int)adj[next].size(); ++j) {
			int nnext = adj[next][j];
			--in[nnext];
		}
		ret = dfs(visited, selected) || ret;
		visited[next] = false;
		selected.pop_back();
		for (int j=0; j<(int)adj[next].size(); ++j) {
			int nnext = adj[next][j];
			++in[nnext];
		}
	}
	return ret;
}


int main () {
	int t;
	scanf("%d",&t);
	getchar();
	for (int tt=1; tt<=t; ++tt) {
		char input[1000];
		gets(input);
		gets(input);

		int len = strlen(input);
		nodes.clear();
		for (int i=0; i<len; i+=2)
			nodes += string(1, input[i]);

		sort(nodes.begin(), nodes.end());
		V = nodes.size();
		for (int i=0; i<V; ++i) {
			toInt[nodes[i]] = i;
			adj[i].clear();
		}

		gets(input);
		len = strlen(input);
		memset(in, 0, sizeof(in));
		for (int i=0; i<len; i+=4) {
			char a = input[i], b = input[i+2];
			adj[toInt[a]].push_back(toInt[b]);
			++in[toInt[b]];
		}

		vb visited(V, false);
		vi selected;
		if (tt > 1) puts("");
		if (!dfs(visited, selected)) printf("NO\n");
	}

	return 0;
}


