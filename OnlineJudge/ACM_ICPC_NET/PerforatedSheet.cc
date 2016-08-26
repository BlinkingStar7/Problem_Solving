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

double ss(double r, vector<int>& x, vector<int>& width, vector<int>& height) {
	double numer = 0;
	for (int i=0; i<width.size(); ++i)
		numer += (2*x[i] + width[i])*(width[i]*height[i]);
	return r - numer;
}

int main() {
		int sheetWidth, sheetHeight;
		vector <int> x, y, width, height;
		int n;
		scanf("%d", &n);
		scanf("%d%d", &sheetWidth, &sheetHeight);
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			x.push_back(t);
		}
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			y.push_back(t);
		}
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			width.push_back(t);
		}
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			height.push_back(t);
		}


		long long w = (long long)sheetHeight * sheetWidth;
		for (int i=0; i<width.size(); ++i)
			w -= (long long)width[i]*height[i];
		if (w == 0) return 0;

		double xx = ss(sheetWidth*sheetWidth*sheetHeight, x, width, height)/2.0/w;
		double yy = ss(sheetHeight*sheetWidth*sheetHeight, y,height, width)/2.0/w;
		printf("%lf %lf\n", xx, yy);
		return 0;
}





