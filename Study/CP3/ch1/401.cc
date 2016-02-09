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

char m[300];

void init() {
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
	string rev = "A...3..HIL.JM.O...2TUVWXY51SE.Z..8.O ";

	for (int i=0; i<abc.size(); ++i)
		m[abc[i]] = rev[i];
}

int main () {
	init();
	char input[50];
	while (gets(input)) {
		bool pal=true, mir=true;
		int len = strlen(input);
		for (int i=0; i<len; ++i) {
			if (input[len-1-i] != input[i]) pal = false;
			if (input[len-1-i] != m[input[i]]) mir = false;
		}

		printf("%s -- ",input);
		if (pal && mir) printf("is a mirrored palindrome.\n");
		if (!pal&& mir) printf("is a mirrored string.\n");
		if (pal &&!mir) printf("is a regular palindrome.\n");
		if (!pal&&!mir) printf("is not a palindrome.\n");
		puts("");
	}
	return 0;
}

