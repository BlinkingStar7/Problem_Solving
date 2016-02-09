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
	while(1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int a, b;
		scanf("%d%d",&a,&b);
		for (int i=0; i<n; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			if (a==x || b == y)
				cout << "divisa" << '\n';
			else if (x > a && y > b)
				cout << "NE" << '\n';
			else if (x < a && y > b)
				cout << "NO" << endl;
			else if (x > a && y < b)
				cout << "SE" << endl;
			else
				cout << "SO" << endl;
		}
	}

	return 0;
}

