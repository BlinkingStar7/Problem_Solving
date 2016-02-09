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

int A, B;
int GCD (int a, int b)
{ return a==0?b:GCD(b%a, a);}

void Solve (int perOne, int index, vector<pair<int, int> > &factor) {
	if (factor.size() == index) {
		printf("%d %d %d\n", perOne, A/perOne, B/perOne);
		return;
	}
	
	pair<int, int> f = factor[index];

	for (int i=0; i<=f.second; ++i) {
		Solve (perOne, index+1, factor);
		perOne *= f.first;
	}
}

vector<pair<int, int> > getFactor(int gcd) {
	int sqrtn = sqrt(gcd);
	vector<pair<int, int> > ret;
	for (int i=2; i<=sqrtn; ++i) {
		int num = 0;
		while (gcd%i==0) {
			++num;
			gcd/=i;
		}
		if (num != 0) ret.push_back(make_pair(i, num));
	}
	if (gcd != 1) ret.push_back(make_pair(gcd, 1));
	return ret;
}


int main () {
	cin >> A >> B;
	int gcd = GCD(A, B);
	vector<pair<int,int> > x= getFactor(gcd);
	Solve (1,0, x);

	return 0;
}

