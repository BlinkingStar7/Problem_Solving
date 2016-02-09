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

int n, m;
char Board[1000][1000], toFind[1000][1000];
void cw() {
	char temp[1000][1000];
	for (int i=0; i<m; ++i)
		for (int j=0; j<m; ++j)
			temp[i][j] = toFind[m-1-j][i];

	for (int i=0; i<m; ++i)
		for (int j=0; j<m; ++j)
			toFind[i][j] = temp[i][j];
}
int main () {
	while(scanf("%d%d", &n, &m)) {
		if (n == 0) break;

		getchar();
		for (int i=0; i<n; ++i)
			scanf("%s", Board[i]);
		for (int i=0; i<m; ++i)
			scanf("%s", toFind[i]);

		for (int r=0; r<4; ++r){
			int num=0;
			for (int i=0; i<=n-m; ++i)
				for (int j=0; j<=n-m; ++j) {
					bool flag = true;
					for (int k=0; k<m;++k) {
						for (int l=0;l<m;++l)
							if (Board[i+k][j+l] != toFind[k][l]) {
								flag = false;
								break;
							}
						if (!flag)
							break;
					}
					if (flag) ++num;
				}
			printf("%d%c",num, r==3?'\n':' ');
			cw();
		}

	}
	return 0;
}

