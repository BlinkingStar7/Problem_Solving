#include <bits/stdc++.h>
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

int main () {
	int t;
	cin >> t;
	getchar();
	for (int test = 1; test<=t; ++test) {
		char input[10001], ch;
		int pos = 0;
		while((ch = getchar()) != '\n') 
			if (isalpha(ch))
				input[pos++] = ch;
		input[pos] = '\0';
		
		int len = strlen(input), sqrtn = sqrt(len);
		bool ans = true;
		if (len != sqrtn*sqrtn) ans = false;

		char second[10001];
		if (ans) {
			int cnt = 0;
			for (int i=0; i<sqrtn; ++i)
				for (int j=0; j<sqrtn; ++j)
					second[cnt++] = input[sqrtn*j+i];
		}

		for (int i=0; i<len; ++i)
			if (input[i] != input[len-1-i] || second[i] != second[len-1-i]) {
				ans = false;
				break;
			}

		printf("Case #%d:\n", test);
		if (ans) printf("%d\n", sqrtn);
		else printf("No magic :(\n");
	}


	return 0;
}

