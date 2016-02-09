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
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		bitset<32> bit(n), a, b;
		int num = 0;
		for (int i=0; i<32; ++i)
			if (bit[i]) {
				++num;
				if (num%2) a.set(i);
				else b.set(i);
			}
		printf("%d %d\n", a.to_ulong(), b.to_ulong());
	}

	return 0;
}

