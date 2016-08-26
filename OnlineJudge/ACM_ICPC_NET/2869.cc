#include <iostream>
using namespace std;
 
typedef long long ll;
int main() {
    ll a, b, v;
    cin >> a >> b >> v;
	if (v <= a) {
		cout << 1 << endl;
		return 0;
	}
    ll day = (v-a)/(a-b);
     
    cout << day + (day % (a-b) ? 2 : 1) << endl;
}

