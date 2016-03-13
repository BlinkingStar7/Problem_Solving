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

string str[9] = {
	"000000",
	"001111",
	"010011",
	"011100",
	"100110",
	"101001",
	"110101",
	"111010"
};

int main () {
	int n;
	char input[200];
	scanf("%d ", &n);
	gets(input);
	int output[20];

	for (int i=0; i<n; ++i) {
		int best = 2, ans = -1;
		for (int s=0; s<8; ++s) {
			int diff = 0;
			for (int j=0; j<6; ++j)
				if(input[6*i+j] != str[s][j]) ++diff;
			if (diff < best) {
				best = diff;
				ans = s;
			}
		}
		if (ans == -1) {
			printf("%d\n",i+1);
			return 0;
		}
		output[i] = ans;
	}

	for (int i=0; i<n; ++i)
		printf("%c", 'A'+output[i]);
	return 0;
}


