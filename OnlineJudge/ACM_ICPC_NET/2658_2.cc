#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
  
char s[11][11];
std::vector<std::pair<int,int> > a;
int an;
  
int val(int x,int y)
{
    if(x<0||x>=10||y<0||y>=10)return 0;
    return s[x][y]-'0';
}
  
int deg(int x,int y)
{
    return val(x-1,y-1)+val(x-1,y)+val(x-1,y+1)+val(x,y+1)+val(x+1,y+1)+val(x+1,y)+val(x+1,y-1)+val(x,y-1);
}
  
int ccw(int ax,int ay,int bx,int by,int cx,int cy)
{
    int t = (ax*by+bx*cy+cx*ay)-(ay*bx+by*cx+cy*ax);
    return t>0?1:t<0?-1:0;
}
  
int dist(int ax,int ay,int bx,int by)
{
    return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}
  
int line(int ax,int ay,int bx,int by,int cx,int cy)
{
    int x,y,z;
    x = dist(ax,ay,bx,by);
    y = dist(ax,ay,cx,cy);
    z = dist(bx,by,cx,cy);
    return fabs(sqrt(x)-sqrt(y)-sqrt(z))<0.01;
}
  
int main()
{
    int u,v,w,x,y,z;
    int i,j;
    for(i=0;i<10;i++)scanf("%s",s[i]);
    for(i=0;i<10;i++)for(j=0;j<10;j++)if(s[i][j]=='1'&&deg(i,j)<=3) {
		a.push_back(std::make_pair(i,j));	
		s[i][j] = '2';
	}
	for (int i=0; i<10; ++i) printf("%s\n", s[i]);
    if(a.size()<3)return puts("0")*0;
    else
    {
        std::sort(a.begin(),a.end());
        for(i=0;i<10;i++)for(j=0;j<10;j++)
        {
            u = ccw(a[0].first,a[0].second,a[1].first,a[1].second,i,j);
            v = ccw(a[1].first,a[1].second,a[2].first,a[2].second,i,j);
            w = ccw(a[2].first,a[2].second,a[0].first,a[0].second,i,j);
            x = line(a[0].first,a[0].second,a[1].first,a[1].second,i,j);
            y = line(a[1].first,a[1].second,a[2].first,a[2].second,i,j);
            z = line(a[2].first,a[2].second,a[0].first,a[0].second,i,j);
            if(val(i,j)!=((u==v&&v==w)||x||y||z))return puts("0")*0;
        }
    }
    printf("%d %d\n%d %d\n%d %d\n",a[0].first+1,a[0].second+1,a[1].first+1,a[1].second+1,a[2].first+1,a[2].second+1);
}
