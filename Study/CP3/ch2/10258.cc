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

struct contestant {
	int score, time, index, wa[10];
	bool solved[10], submit;
	contestant () {}
	contestant (int i) : index(i), score(0), time(0), submit(false) {
		memset(wa, 0, sizeof(wa));
		memset(solved, 0, sizeof(solved));
	}
} C[101];

bool compare (const contestant& A, const contestant& B) {
	return A.score != B.score ? A.score > B.score : A.time != B.time ? A.time < B.time : A.index < B.index;}
	
int main () {
	int t;
	scanf("%d ",&t);
	bool f = false;
	while(t--) {
		for (int i=0; i<=100; ++i)
			C[i] = contestant(i);
		char input[100];
		while (gets(input)) {
			if (input[0] == '\0') break;
			int c, p, t;
			char l;
			sscanf(input, "%d %d %d %c", &c,&p,&t,&l);
			C[c].submit = true;
			if (l == 'C') {
				if (!C[c].solved[p]) {
					C[c].solved[p] = true;
					C[c].time += t + 20*C[c].wa[p];
					C[c].score++;
				}
			}
			else if (l == 'I') {
				if (!C[c].solved[p]) 
					++C[c].wa[p];
			}
		}
		sort(C+1, C+101, compare);
		if(!f) f=true;
		else puts("");
		for(int i=1; i<=100; ++i) {
			if (!C[i].submit) continue;
			printf("%d %d %d\n", C[i].index, C[i].score, C[i].time);
		}
	
	}


	return 0;
}

