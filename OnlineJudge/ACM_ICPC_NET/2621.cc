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

int mm[300], n[20], s[5];
int num[6], mmax=-1;
int main () {
	mm['R'] = 0, mm['B'] = 1, mm['Y'] = 2, mm['G'] = 3;
	for (int i=0; i<5; ++i) {
		char suit; int num;
		scanf("%c%d",&suit, &num);
		getchar();
		s[mm[suit]]++; n[num]++;
	}

	bool flush = false, straight = false;
	for (int i=2; i<=5; ++i) {
		for (int j=1; j<=9; ++j) {
			if (n[j] == i) ++num[i];
			if (n[j]) mmax = max(mmax, j);
		}
	}

	for (int i=0; i<4; ++i) if (s[i] == 5) flush = true;
	for (int i=5; i<=9; ++i) if (n[i] == 1) {
		bool temp = true;
		for (int j=0; j<5; ++j)
			if (n[i] != n[i-j]) {
				temp = false;
				break;
			}
		straight = straight || temp;
	}

	int ans = 0;
	if (flush && straight) ans = 900 + mmax;
	else if(num[4]) {
		ans = 800;
		for (int i=1; i<=9; ++i)
			if (n[i] == 4) ans += i;
	}
	else if(num[3] && num[2]) {
		ans = 700;
		for (int i=1; i<=9; ++i)
			if (n[i] == 3) ans += i*10;
			else if (n[i] == 2) ans += i;
	}
	else if (flush) ans = 600 + mmax;
	else if (straight) ans = 500 + mmax;
	else if (num[3]) {
		ans = 400;
		for (int i=1; i<=9; ++i)
			if (n[i] == 3) ans += i;
	}
	else if (num[2] == 2) {
		ans = 300;
		int mul = 1;
		for (int i=1; i<=9; ++i) {
			if (n[i] == 2) {
				ans += mul*i;
				mul *= 10;
			}
		}
	}
	else if (num[2]) {
		ans = 200;
		for (int i=1; i<=9; ++i)
			if (n[i] == 2) ans += i;
	}
	else ans = 100 + mmax;

	printf("%d\n", ans);
	return 0;
}


