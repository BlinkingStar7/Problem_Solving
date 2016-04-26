#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef vector<int> vi;
 
char buf[1155555];

struct SuffixComparator{
    const vi group;
    int t;
    SuffixComparator(const vi& _group, int _t) :
        group(_group), t(_t) {}
    bool operator() (int i, int j){
        if(group[i] != group[j]) return group[i] < group[j];
        else return group[i+t] < group[j+t];
    }
};
 
vi suffix_array(const string& s){
    int n = s.size(), len = 1;
    vi grp(n+1), ret(n);
    for(int i=0;i<n;i++){
        grp[i] = s[i] - 'a';
        ret[i] = i;
    }
    grp[n] = -1;
    while(len < n){
        SuffixComparator cmp(grp, len);
        sort(ret.begin(), ret.end(), cmp);
        int cnt = 1;
        grp[ret[0]] = 1;
        for(int i=1;i<n;i++){
            if(cmp(ret[i-1], ret[i])) cnt++;
            grp[ret[i]] = cnt;
        }
        len *= 2;
    }
    return ret;
}
 
vi longest_common_prefix(const string& s, const vi& sa){
    int n = sa.size();
    vi lcp(n, 0), sa_inv(n);
    for(int i=0;i<n;i++) sa_inv[sa[i]] = i;
    for(int i=0;i<n;i++){
        if(sa_inv[i] == 0) continue;
        int l = i?max(lcp[sa_inv[i]-1]-1, 0):0;
        int j = sa[sa_inv[i]-1];
        for(;i+l<s.size()&&j+l<s.size()&&s[i+l]==s[j+l];l++);
        lcp[sa_inv[i]] = l;
    }
    return lcp;
}
 
int main(){
	gets(buf);
	string s(buf);
    int n = s.size(); 
    vi sa = suffix_array(s);
	for (int i=0; i<n; ++i)
		printf("%s\n", buf +sa[i]);
    vi lcp = longest_common_prefix(s, sa);
    long long cnt = 0;
    for(int i=0;i<sa.size();i++){
        cnt += n - sa[i] - lcp[i];
    }
    cout << cnt << endl;
    return 0;
}
