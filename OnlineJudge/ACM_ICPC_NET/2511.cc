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
	int a[11], b[11];
	for (int i=0; i<10; ++i) scanf("%d", a+i);
	for (int i=0; i<10; ++i) scanf("%d", b+i);

	int x=0, y=0, last = -1;
	for (int i=0; i<10; ++i) {
		if (a[i] > b[i]) {x+=3; last = 0;}
		else if (a[i] < b[i]) {y+=3; last = 1;}
		else {++x; ++y;}
	}

	printf("%d %d\n", x, y);
	if (x != y) printf("%c\n", x > y ? 'A' : 'B');
	else {
		if (last == -1) printf("D\n");
		else printf("%c\n", last ? 'B' : 'A');
	}
	
	
	return 0;
}


