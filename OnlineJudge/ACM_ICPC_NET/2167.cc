#include <bits/stdc++.h>
using namespace std;
int r, c, board[301][301];
int main() {
    scanf("%d%d",&r,&c);
    for (int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) {
        scanf("%d", &board[i][j]);
        board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
    }
    int k;
    scanf("%d", &k);
    for (int i=0; i<k; ++i) {
        int x,xx,y,yy;
        scanf("%d%d%d%d",&y,&x,&yy,&xx);
        printf("%d\n", board[yy][xx] - board[y-1][xx] - board[yy][x-1] + board[y-1][x-1]);
       
    }
    return 0;
}
