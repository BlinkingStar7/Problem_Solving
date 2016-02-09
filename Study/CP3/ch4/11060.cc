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
using namespace std;
#define PI 2*acos(0.0)
#define IFN 1e8
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

int n, m;
vi adj[101], ans;
vb visited;
string word[101];

int cnt = 1;

void Kahn() {
	vi in(n, 0);
	for(int i=0; i<n; ++i)
		for(int j=0; j<adj[i].size(); ++j) 
			in[adj[i][j]]++;
	priority_queue<int> pq;
	for (int i=0; i<n; ++i)
		if(in[i] == 0)
			pq.push(-i);

	while(!pq.empty()) {
		int cur = -pq.top(); pq.pop();
		ans.push_back(cur);
		for (int i=0; i<adj[cur].size(); ++i) {
			in[adj[cur][i]]--;
			if (in[adj[cur][i]] == 0)
				pq.push(-adj[cur][i]);
		}
	}
}
	
int main () {
	while(scanf("%d",&n) != EOF) {
		map<string, int> toInt;
		for (int i=0; i<n; ++i)
			adj[i].clear();
		ans.clear();

		for (int i=0; i<n; ++i) {
			cin >> word[i];
			toInt[word[i]] = i;
		}
		scanf("%d", &m);
		for (int i=0; i<m; ++i) {
			string from, to;
			cin >> from >> to;
			adj[toInt[from]].push_back(toInt[to]);
		}

		Kahn();
		
		printf("Case #%d: Dilbert should drink beverages in this order:", cnt++);
		for (int i=0; i<(int)ans.size(); ++i)
			cout << " " << word[ans[i]];
		printf(".\n\n");
	}

	return 0;
}

