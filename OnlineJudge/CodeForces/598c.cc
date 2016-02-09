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

const double PI = 2*acos(0.0);

struct vector2 {
	int index;
	double x, y;
	explicit vector2(int _i=0, double _x=0, double _y =0) : index(_i), x(_x), y(_y) {}
	bool operator < (const vector2& rhs) const {
		return this->polar() < rhs.polar();
	}
	double polar() const  {
		return fmod(atan2(y,x) + 2*PI, 2*PI);
	}
};

int N;
vector<vector2> vec;

int main () {

	cin >> N;
	vec.resize(N);

	for (int i=0; i<N; ++i) {
		int x, y;
		scanf("%d%d",&x,&y);
		vec[i] = vector2(i+1, x, y);
	}

	sort(vec.begin(), vec.end());

#ifdef DEBUG
	for (int i=0; i<N; ++i)
		printf("%d : %lf\n", i+1, vec[i].polar());
#endif
	double Min = vec[0].polar() - vec[N-1].polar() + 2*PI;
	if (Min >= PI) Min = 2*PI - Min;
	int ans1 = vec[N-1].index, ans2 = vec[0].index;
	for (int i=0; i<N-1; ++i) {
		double cand = vec[i+1].polar() - vec[i].polar();
		if (cand >= PI) cand = 2*PI - cand;
		if (cand < Min) {
			ans1 = vec[i+1].index;
			ans2 = vec[i].index;
			Min = cand;
		}
	}

	printf("%d %d\n", ans1, ans2);
	return 0;
}

