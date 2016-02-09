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
using namespace std;
#define EP (1e-100)
struct rec {
	double x, xx, y, yy;
};

rec Rectangles[31];
int N;


int hit (double ax1, double ax2, double ay1, double ay2,
		double bx1, double bx2, double by1, double by2)
{
	if (ax1 >= bx1 && ax2 <= bx2 && ay1 >= by1 && ay2 <= by2) return 1;
	else return 0;
}
int main () {
	cin >> N;
	vector<double> xPoints, yPoints;
	for (int i=0; i<N; ++i) {
		double x, y, w, h;
		scanf("%lf%lf%lf%lf", &x,&y,&w,&h);
		Rectangles[i] = (rec) {x, x+w, y, y+h};
		xPoints.push_back(x);
		xPoints.push_back(x+w);
		yPoints.push_back(y);
		yPoints.push_back(y+h);
	}
	sort(xPoints.begin(), xPoints.end());
	sort(yPoints.begin(), yPoints.end());

	double ans = 0;

	for (int i=0; i<xPoints.size()-1; ++i)
		for (int j=0; j<yPoints.size()-1; ++j) {
			double x=xPoints[i], xx=xPoints[i+1], y=yPoints[j], yy=yPoints[j+1];
			for (int k=0; k<N; ++k) {
				if (hit (x, xx, y, yy, Rectangles[k].x, Rectangles[k].xx, Rectangles[k].y, Rectangles[k].yy)) {
					ans += (xx-x)*(yy-y);
					break;
				}
			}
		}


	if (ans == (int)ans)
		printf("%d\n", (int)(ans*100)/100);
	else 
		printf("%.2lf\n", ans);

	return 0;
}

