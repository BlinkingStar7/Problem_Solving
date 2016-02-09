#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
int main() {
	char str[20], num[26] = {};
	cin >> N >> str;
	int ans = 0;
	for (int i=0; i<strlen(str); ++i)
		++num[str[i]-'A'];
	for (int i=0; i<N-1; ++i) {
		char cur[26] = {};
		cin >> str;
		for (int j=0; j<strlen(str); ++j)
			++cur[str[j]-'A'];
		int minus = 0, plus = 0, flag = 1;
		for (int i=0; i<26; ++i)
			if (abs(num[i]-cur[i]) > 1) flag = 0;
			else if (num[i]-cur[i] == 1) ++plus;
			else if (num[i]-cur[i] == -1) ++minus;
		if (flag && ((plus == 1 && minus == 1) || (plus + minus <= 1))) ++ans;
	}
	cout << ans << endl;


	return 0;
}


