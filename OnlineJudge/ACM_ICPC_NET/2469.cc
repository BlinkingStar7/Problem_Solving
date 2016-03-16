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
	int k, n;
	char tobe[30], cur[30], input[30], a[100][30];
	scanf("%d %d ", &k, &n);

	for (int i=0; i<k; ++i) cur[i] = 'A'+i;

	gets(tobe);
	while (1) {
		--n;
		gets(input);
		if (input[0] == '?') break;
		for (int j=0; j<k-1; ++j)
			if (input[j] == '-') swap(cur[j], cur[j+1]);
	}
	int cnt = 0;
	while (n && gets(a[cnt])) {
		--n;
		++cnt;
	}

	for (int i=cnt-1; i>=0; --i) {
		for (int j=0; j<k-1; ++j)
			if (a[i][j] == '-') swap(tobe[j], tobe[j+1]);
	}

	char ans[30];
	for (int i=0; i<k-1; ++i) {
		if (cur[i] == tobe[i]) ans[i] = '*';
		else if (cur[i] == tobe[i+1] && cur[i+1] == tobe[i]) {
			ans[i] = '-';
			swap(cur[i], cur[i+1]);
		}
		else {
			cout << string(k-1, 'x') << endl;
			return 0;
		}
	}
	for (int i=0; i<k-1; ++i)
		printf("%c", ans[i]);
	
	return 0;
}


