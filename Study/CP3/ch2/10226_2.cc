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
	scanf("%d ", &t);

	for (int test=0; test<t; ++test) {
		string s;
		map<string, int> tree;
		int total=0;
		while (getline(cin, s) && s != "") {
			tree[s]++;
			total++;
		}

		if (test != 0) puts("");
		for (map<string, int>::iterator it = tree.begin(); it != tree.end(); ++it)
			printf("%s %.4lf\n", it->first.c_str(), (double)(it->second)/total*100.0);
	}

	return 0;
}

