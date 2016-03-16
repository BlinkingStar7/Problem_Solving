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

int score[7][3];

bool solve(int a, int b) {
	if (a == 6) return true;
	if (b == 6) return solve(a+1, a+2);

	for (int i=0; i<3; ++i) {
		if (score[a][i] && score[b][2-i]) {
			--score[a][i], --score[b][2-i];
			if (solve(a, b+1)) return true;
			++score[a][i], ++score[b][2-i];
		}
	}
	return false;
}
		
	 
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
		if (ans && solve(0, 1)) printf("1 ");
		else printf("0 ");
	}		
	return 0;
}


