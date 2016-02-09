#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const char Digit[2][5] = {"IXCM", "VLD"};
const string Four[2][3] = {"IV", "XL", "CD", "IX", "XC", "CM"};
string strA, strB;
int A, B, Rome[26];

int romeToNum (string &s) {
	int ret = 0;
	for (int i=0; i<s.size(); ++i) {
		if (i < s.size()-1) {
			int here = Rome[s[i]-'A'], next = Rome[s[i+1]-'A'];
			if (here >= next)
				ret += here;
			else
				ret -= here;
		}
		else
			ret += Rome[s[i]-'A'];
	}
	return ret;
}

string numToRome (int num, int digit) {
	if (num == 0)  return "";
	int cur = num%10;
	if (cur%5 == 4)
		return numToRome(num/10, digit+1) + Four[cur/5][digit];
	else {
		string ret(cur%5, Digit[0][digit]);
		if (cur/5)
			ret = Digit[1][digit] + ret;
		return numToRome(num/10, digit+1) + ret;
	}
}




int main() {
	cin >> strA >> strB;
	Rome['I'-'A'] = 1;
	Rome['V'-'A'] = 5;
	Rome['X'-'A'] = 10;
	Rome['L'-'A'] = 50;
	Rome['C'-'A'] = 100;
	Rome['D'-'A'] = 500;
	Rome['M'-'A'] = 1000;
	int A = romeToNum(strA), B = romeToNum(strB);
	cout << A + B << endl;
	cout << numToRome(A+B, 0) << endl;





	return 0;
}


