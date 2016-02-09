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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int t;
	scanf("%d ",&t);
	for (int test=0; test<t; ++test) {
		string s;
		int cnt = 0;
		map<string, int> tree;
		vi num(10001);
		vector<pair<string, int> > name;
		int total = 0;
		while (1) {
			getline(cin, s);

			if (s.empty()) break;
			if (tree.find(s) == tree.end()) {
				name.push_back(make_pair(s, cnt));
				tree[s] = cnt++;
			}
			
			num[tree[s]]++;
			++total;
		}
		sort(name.begin(), name.end());

		if (test != 0) puts("");
		for (int i=0; i<name.size(); ++i) 
			printf("%s %.4lf\n", name[i].first.c_str(), (double)num[name[i].second]*100/total);
	}




	return 0;
}

