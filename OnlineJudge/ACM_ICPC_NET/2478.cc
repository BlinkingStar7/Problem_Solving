#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int N, Arr[501];
int main () {
    cin >> N;
    for (int i=0; i<N; ++i)
        scanf("%d", Arr+i);
    Arr[N] = Arr[0];

    int start=-1, num=0;
    bool found = false;

    for (int i=0; i<N; ++i) {
        if (Arr[i] == Arr[i+1]+1 || (Arr[i]==1 && Arr[i+1]==N)) {
            ++num;
            if (!found) {
                start = i;
                found = true;
            }

        }
        else
            found = false;
    }
    if (num != 0 && num != N) ++num;

	if (num == 0) {
		for (int i=0; i<N; ++i)
			if (Arr[i] == 1) {
				printf("%d\n%d %d\n%d\n", N-i,1,1,N);
			}
		return 0;
	}


    reverse(Arr+start, Arr+start+num);

    for (int i=0; i<N; ++i)
        if (Arr[(start+i)%N] == 1) {
            printf("%d\n", N-i);
            break;
        }

    printf("%d %d\n",1, num);
    printf("%d\n", N-start); // last



    return 0;
}

