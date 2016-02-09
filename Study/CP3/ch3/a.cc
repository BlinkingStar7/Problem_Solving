#include<bits/stdc++.h>

using namespace std;

string pat;
string input;

int dp[200][200];

int mymatch(int a, int b) {

	if(a == pat.size()){
		return (b==input.size() ? 1 : 0);
	}
	else if(b==input.size()) {
		int k=1;
		for(int i=a; i<pat.size(); ++i)
			if(pat[i]!='*') k=0;
		return k;
	}
	else{
		int &ret = dp[a][b];
		if(ret != -1) return ret;

		if(pat[a]=='*') {
			int k=0;
			for(int i=b; i<=input.size(); ++i)
				k += mymatch(a+1, i);
			if(k>1) k=1;
			return ret=k;
		}

		if(pat[a]==input[b] || pat[a]=='?')
			return ret=mymatch(++a, ++b);
	}
}

int main() {
	int c;
	cin >> c;
	while(c--) {
		int n;
		cin >> pat;
		cin >> n;

		vector<string> v;
		for(int i=0; i<n; ++i) {
			cin >> input;
			memset(dp, -1, sizeof(dp));
			if(mymatch(0,0)==1)
				v.push_back(input);
		}

		sort(v.begin(), v.end());
		for(int i=0; i<v.size();++i)
			cout << v[i] <<endl;


	}

	return 0;
}
