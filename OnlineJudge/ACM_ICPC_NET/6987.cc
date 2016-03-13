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

bool solve(int cur) {
	if (cur == 6) return true;

	int &w=score[cur][0], &d=score[cur][1], &l=score[cur][2];
	for (int opp=0; opp<6; ++opp) if (opp != cur) {

int main () {
	for (int i=0; i<4; ++i) {
		bool ans = true;
		for (int j=0; j<6; ++j) {
			int sum = 0;
			for (int k=0; k<3; ++k) {
				scanf("%d", &score[j][k]);
				sum += score[j][k];
			}
			if (sum != 5) ans = false;
		}
		if (ans && solve()) printf("1 ");
		else printf("0 ");
	}		
	return 0;
}


