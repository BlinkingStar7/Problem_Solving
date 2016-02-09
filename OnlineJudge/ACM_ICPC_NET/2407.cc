#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
string C[101][101];

string Add (string &a, string &b) {
	vector<int> result (max(a.size(),b.size())+1, 0);

	int carry = 0;
	string ret;
	for (int i=0; i<result.size(); ++i) {
		result[i] = (i>=a.size() ? 0 : a[i]-'0') + (i>=b.size() ? 0 : b[i]-'0') + carry;
		carry = result[i]/10;
		result[i] %= 10;
		ret.push_back(result[i]+'0');
	}

	while (ret.back() == '0') ret.pop_back();

	return ret;
}


int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i=0; i<=N; ++i)
        for (int j=0; j<=i; ++j) {
            C[i][j] = (j==0 || j==i) ? "1" : Add(C[i-1][j-1], C[i-1][j]);
		}
	reverse(C[N][M].begin(), C[N][M].end());
	cout << C[N][M] << endl;
	return 0;
}
