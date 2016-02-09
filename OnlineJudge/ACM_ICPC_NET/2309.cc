#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int H[9];
	for (int i=0; i<9; ++i)
		scanf("%d", H+i);
	sort(H, H+9);
	while(1) {
		int s = 0;
		for (int i=0; i<7; ++i)
			s += H[i];
		if (s == 100 ){
			for (int i=0; i<7; ++i)
				cout << H[i] << endl;
			break;
		}
		next_permutation(H, H+9);
	}
	return 0;
}


