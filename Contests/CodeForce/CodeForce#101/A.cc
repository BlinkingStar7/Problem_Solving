#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int alpha[26];
int main () {
	string s;
	for (int i=0; i<2; ++i) {
		cin >> s;
		for (int j=0; j<s.size(); ++j)
			alpha[s[j]-'A']++;
	}
	cin >> s;
	for (int i=0; i<s.size(); ++i)
		alpha[s[i]-'A']--;
	for (int i=0; i<26; ++i)
		if (alpha[i] != 0) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;

	return 0;
}

