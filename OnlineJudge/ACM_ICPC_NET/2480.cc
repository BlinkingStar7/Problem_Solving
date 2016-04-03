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

int main () {
	int num[7] = {0};
	int t;
	for (int i=0; i<3; ++i) {
		scanf("%d", &t);
		++num[t];
	}

	int *pos = max_element(num, num+7);
	if (*pos == 3) printf("%d\n", 10000+1000*(pos-num));
	if (*pos == 2) printf("%d\n", 1000+100*(pos-num));
	if (*pos == 1) {
		for (int i=6; i>0; --i) {
			if (num[i]) {
				printf("%d\n", 100*i);
				break;
			}
		}
	}


	return 0;
}


