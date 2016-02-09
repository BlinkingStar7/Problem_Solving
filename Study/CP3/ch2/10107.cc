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
	vi l;
	int t;
	while (scanf("%d", &t)!=EOF) 
	{
		l.push_back(t);
		nth_element(l.begin(), l.begin() + l.size()/2, l.end());
		int hi = l[l.size()/2], lo = l.size()%2 ? hi : *max_element(l.begin(), l.begin()+l.size()/2); 
		printf("%d\n", (lo+hi)/2);
	}

	return 0;
}

