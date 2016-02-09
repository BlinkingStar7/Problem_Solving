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
	int k;
	while (scanf("%d", &k) != EOF) {
		vpii ans;
		for (int y=k+1; y<=2*k; ++y) {
			if (y*k % (y-k) == 0) 
				ans.push_back(make_pair(y*k/(y-k), y));
		}
		printf("%d\n", ans.size());
		for (int i=0; i<ans.size(); ++i)
			printf("1/%d = 1/%d + 1/%d\n", k, ans[i].first, ans[i].second);
	}

	return 0;
}


