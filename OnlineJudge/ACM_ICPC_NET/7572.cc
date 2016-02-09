#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif 

string gan = "0123456789", ji = "ABCDEFGHIJKL";

int main () {
	int n;
	scanf("%d", &n);
	n += 2400;
	n -= 2013;
	n %= 60;
	int a='F'-'A', b='9'-'0';
	while (n != 0) {
		b = (b+1)%10;
		a = (a+1)%12;
		n--;
	}

	printf("%c%c\n", ji[a], gan[b]);
		return 0;
}

