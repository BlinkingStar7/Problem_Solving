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
	int n;
	vi score;
	for (int i=1; i<=3; ++i) for (int j=1; j<=20; ++j)
		score.push_back(i*j);
	score.push_back(50); score.push_back(0);
	sort(score.begin(), score.end());
	score.erase(unique(score.begin(), score.end()), score.end());

	while (scanf("%d", &n) && n > 0) {
		int combi=0, permu=0;
		for (int a=0; a<score.size(); ++a)
			for (int b=a; b<score.size(); ++b)
				for (int c=b; c<score.size(); ++c) {
					if (score[a] + score[b] + score[c] == n) {
						DPRINTF(("%d %d %d\n", score[a], score[b], score[c]));
						++combi;
						if (a == b && b == c) ++permu;
						else if (a == b || b == c) permu+=3;
						else permu+=6;
					}
				}
		if (combi == 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combi);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permu);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}


