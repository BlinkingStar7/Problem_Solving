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

const long double PI = acos(-1);
struct vec {
	int id;
	long double x, y, ang;
};

bool compare (const vec &a, const vec &b) {
	return a.ang < b.ang;
}
int N;
int main () {
	cin >> N;
	vector<vec> v(N);
	for (int i=0; i<N; ++i) {
		int id = i+1;
		long double x, y, ang;
		scanf("%Lf %Lf", &x, &y);
		ang = fmod(atan2(y, x)+2*PI, 2*PI) ;
		v[i] = (vec) {id, x, y, ang};
	}

	sort(v.begin(), v.end(), compare);
	for (int i=0; i<N; ++i)
		printf("%d : %.10Lf\n", i+1, v[i].ang);
	int id1, id2;
	long double Min = 987654321, temp;
	for (int i=1; i<N; ++i) {
		temp = v[i].ang - v[i-1].ang;
		temp = min (temp, 2*PI - temp);
		if (Min > temp) {
			id1 = v[i-1].id;
			id2 = v[i].id;
			Min = temp;
		}
	}
	temp = v[N-1].ang - v[0].ang;
	temp = min (temp, 2*PI - temp);
	if (temp < Min) {
		printf("%d %d\n", v[0].id, v[N-1].id);
	}
	else
		printf("%d %d\n", id1, id2);

		

	return 0;
}

