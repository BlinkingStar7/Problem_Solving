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

int m[300];
int main () {
	int n;
	cin >> n;
	while(n--) {
		memset(m, 0, sizeof(m));
		int k;
		scanf("%d", &k);
		for (int i=0; i<k; ++i) {
			getchar();
			unsigned char a;
			int b;
			scanf("%c%d", &a,&b);
			m[a] = b;
		}

		double sum = 0;
		int q;
		cin >> q;
		getchar();
		unsigned char input[12345];
		for (int i=0; i<q; ++i) {
			gets((char*)input);
			for (int j=0; j<strlen((char*)input); ++j)
				sum += m[input[j]];
		}

		printf("%.2lf$\n", sum/100);
	}
	
		
	return 0;
}

