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

double X[10001], Y[10001], N;
int pnpoly(double x, double y) {
	int i,j,c=0;
	for (i=0, j=N-1; i<N; j=i++) {
		if (((Y[i]>y) != (Y[j]>y)) && (x<(y-Y[i])*(X[j]-X[i])/(Y[j]-Y[i]) + X[i]))
			c = !c;
	}
	return c;
}

int onedge(double x, double y) {
	int i,j;
	for (i=0,j=N-1; i<N; j=i++) {
		if ((y-Y[i])*(X[j]-X[i]) == (Y[j]-Y[i])*(x-X[i]))
			return 1;
	}
	return 0;
}
	

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%lf%lf",X+i,Y+i);

	for (int i=0; i<3; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		printf("%d\n", pnpoly(x, y)||onedge(x, y));
	}

	return 0;
}

