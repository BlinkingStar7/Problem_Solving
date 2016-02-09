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
#include <numeric>
using namespace std;
int num['Z' - 'A' + 1];

int main () {
	string s;
	cin >> s;
	for (int i=0; i<s.size(); ++i) {
		++num[s[i]-'A'];
	}

	int x = -1;
	for (int i=0; i<'Z'-'A'+1; ++i) {
		if (num[i] % 2) {
			if (x != -1) {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			x = i;
		}
	}
	string ans;
	for (int i=0; i<'Z'-'A'+1; ++i) 
		if (num[i] != 0) {
			string a(num[i]/2, 'A' + i);
			ans += a;
		}

	string rev = ans;
	reverse (rev.begin(), rev.end());
	if (x != -1)
		cout << ans << (char)('A' + x) << rev << endl;
	else
		cout << ans << rev << endl;


	return 0;
}

