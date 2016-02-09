#include<cstdio>
#include<cstring>
using namespace std;

int m,n,c;
int t[30],ca[20],inside_ca[20];
int current,Max=0,best;

int count(int a)
{
	int n = 0;
	while(a!=0)
	{
		n++;
		a-=(a&(-a));
	}
	return n;
}
int main()
{
	int TC = 1;
	while(scanf("%d %d",&m,&n),m)
	{
		Max = 0;
		memset(inside_ca,0,sizeof(inside_ca));
		for(int i=0;i<m;i++)
			scanf("%d",&t[i]);
		scanf("%d",&c);
		for(int i=0;i<c;i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=0;j<x;j++)
			{
				int p;
				scanf("%d",&p);
				inside_ca[i]|=1<<(p-1);
			}
			scanf("%d",&ca[i]);
		}
		
		for(int k=1;k<(1<<(m));k++)
		if(count(k)==n)
		{
			//printf("%d\n",k);
			int sum = 0;
			for(int i=0;i<m;i++)
				if(k&(1<<i))
				{
					//printf("%d ",i);
					sum+=t[i];
				}
			for(int i=0;i<c;i++)
			{
				int tmp = inside_ca[i]&k;
				if(tmp>1)
				sum-=(count(tmp)-1)*ca[i];

			}
			//if(k==7) for(int i=0;i<c;i++)printf("%d ",area[i]);
			if(sum>Max)
			{
				Max = sum;
				best = k;
			}
		}
		printf("Case Number  %d\n",TC++);
		printf("Number of Customers: %d\n",Max);
		printf("Locations recommended:");
		for(int i=0;i<m;i++)
			if(best&(1<<i))
			printf(" %d",i+1);
		printf("\n\n");

	}
	return 0;
}
