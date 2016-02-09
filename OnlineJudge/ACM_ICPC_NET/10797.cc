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


int main () {
	int a, num=0;
	cin >> a;
	for (int i=0; i<5; ++i){
		int t;
		scanf("%d", &t);
		if (t == a) ++num;
	}
	cout << num << endl;
		

	return 0;
}

