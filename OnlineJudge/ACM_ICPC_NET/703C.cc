#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define EPSILOn 1e-8
#ifdef DEBUG
#define DPRInTF(x) printf x
#else
#define DPRInTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

const int InF = 1000000005;
long long  n, w, v, u;
pair<ll, ll> P[10005];

int main () {
	scanf("%lld%lld%lld%lld", &n, &w, &v, &u);

	int leftUpX = InF, leftUpY = -InF, upLeftX = InF, upLeftY = -InF;
	int botRightX = -InF, botRightY = InF, rightBotX = -InF, rightBotY = InF;

	int a, b, c, d;

	for (int i=0; i<n; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		P[i] = make_pair(x, y);
		if (x < leftUpX || (x == leftUpX && y > leftUpY)) {
			leftUpX = x; leftUpY = y;
			a = i;
		}
		if (y > upLeftY || (y == upLeftY && x < upLeftX)) {
			upLeftX = x; upLeftY = y;
			b = i;
		}
		if (y < botRightY || (y == botRightY && x > botRightX)) {
			botRightX = x; botRightY = y;
			c = i;
		}
		if (x > rightBotX || (x == rightBotX && y < rightBotY)) {
			rightBotX = x; rightBotY = y;
			d = i;
		}
	}

	bool flag = true;
	for (int i=a;  ; i = (i-1+n)%n) {
		if (P[i].first*u < P[i].second*v) {
			flag = false; break;
		}
		if (i == b) break;
	}
	if (flag) { printf("%.10lf\n", (double)w/u); return 0; }

	int bef = 0, bef2 = 0;
	double ans = 0;
	for (int i=c; ; i = (i+1)%n) {
		if ((P[i].first-bef2)*u > (P[i].second-bef)*v) ans += (double)(P[i].first-bef2)/v;
		else break;
		bef = P[i].second;
		bef2 = P[i].first;
		if (i == d) break;
	}

	ans += (double)(w - bef)/u;

	printf("%.10lf\n", ans);
	return 0;
}


