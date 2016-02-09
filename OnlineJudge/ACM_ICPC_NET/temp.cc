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
	string s;
	cin >> s;
	vector<int> ans;
	int base=1, num=0;
	for (int i=s.size()-1; i>=0; --i, base*=2) {
		if (base == 8) {
			ans.push_back(num);
			num = 0;
			base = 1;
		}
		num += (s[i]-'0')*base;
	}
	if (num) ans.push_back(num);
	for (int i=ans.size()-1; i>=0; --i)
		cout << ans[i];
	return 0;
}

