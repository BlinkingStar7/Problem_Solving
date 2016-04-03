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
	int sum=0, num=0, best=0, freq, a[11];
	for (int i=0; i<10; ++i) {
		scanf("%d", a+i);
		sum += a[i];
	}

	sort(a, a+10);
	for (int i=0; i<10; ++i)
		if (i == 0 || a[i] == a[i-1])
			++num;
		else {
			if (num > best) {
				best = num;
				freq = a[i-1];
			}
			num = 1;
		}
	if (num > best) freq = a[9];

	printf("%d\n%d\n", sum/10, freq);

	return 0;
}


