#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
using namespace std;

int testNum, N;

vector<double> Derivative (vector<double> & c) {
	vector<double> ret (c.size()-1);
	for (int i=c.size()-2; i>=0; --i)
		ret[i] = c[i+1]*(i+1);

	return ret;
}

double Fun (vector<double>&c, double x) {
	double ret = 0, k = 1;
	for (int i=0; i<c.size(); ++i) {
		ret += c[i]*k;
		k*=x;
	}
	return ret;
}

double Bin (vector<double>&c, double lo, double hi) {
	if (Fun(c, lo) > 0) return Bin(c, hi, lo);

	for (int it=0; it<100; ++it) {
		double mid = (lo+hi)/2;
		if (Fun(c, mid) <= 0) lo = mid;
		else hi = mid;
	}
	return (hi + lo)/2;
}

vector<double> Solve (vector<double> & c) {
	if (c.size() == 2) { // c[1]x + c[0] = 0
		vector<double> ret(1, -c[0]/c[1]);
		return ret;
	}

	vector<double> range, ans, dev = Derivative(c);
	range = Solve(dev);

	range.push_back (10.1);
	double lo = -10.1, hi;
	for (int i=0; i<range.size(); ++i) {
		hi = range[i];
		ans.push_back(Bin(c, lo, hi));
		lo = hi;
	}

	return ans;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;

		vector<double> coeff(N+1);
		for (int i=N; i>=0; --i)
			cin >> coeff[i];

		vector<double> ret = Solve(coeff);
		for (int i=0; i<N; ++i)
			printf("%s%.10lf",i==0?"":" ",ret[i]);
		cout << endl;

	}


	return 0;
}

