#include <stdio.h>
#include <string.h>
long long d[52][56];
int save[52];
long long n,m;//길이,번째
long long bef,now;
int flag;
void back()
{
	int i,j;
}
int main()
{
	int i,j,k;
	scanf("%lld %lld",&n,&m);

	d[1][1]=1;//)
	d[1][55]=1;//(

	for(i=2;i<=50;i++)
	{
		d[i][0]=d[i-1][1];//(로 닫는경우
		//      d[i][55]=d[i-1][0]+d[i-1][55]*2;//괄호 ㅇㅇ를 (로 닫는경우+d[i-1]의 ㄴㄴ에 더하는경우//인데 계산필요 X일듯
		for(j=1;j<50;j++)
		{
			d[i][j]=d[i-1][j+1]+d[i-1][j-1];
		}
	}
	long long tb=1;
	for(i=0;i<n;i++)
	{
		save[i]=(tb&m)/tb;
		tb*=2;
	}
	if(n%2==0)
	{
		flag=1;
		while(flag==1)
		{
			flag=0;
			//back();
			{
				int safe=0,alr=0;//(갯수,닫힌괄호갯수
				for(i=n-1;i>=0;i--)
				{
					if(save[i]==0)
					{
						safe++;
					}
					else
					{
						safe--;alr++;
						if(safe+alr<n/2)//여태까지 나온 (수가 n/2보다작으면
						{
							now+=d[i][safe+2];
						}
					}
					if(safe==-1)
					{
						break;
					}
					if(alr+safe>n/2)
					{
						break;
					}
				}
				if(i==-1&&safe==0)
				{
					now++;
				}
			}
			now-=bef;
			if(now==0) flag=0;
			else flag=1;

			m+=now;bef+=now;now=0;
			tb=1;
			for(i=0;i<n;i++)
			{
				save[i]=(tb&m)/tb;
				tb*=2;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(save[i]==0)
				printf("(");
			else
				printf(")");
		}
	}
	else//상관없이 2bit
	{
		for(i=n-1;i>=0;i--)
		{
			if(save[i]==0)
				printf("(");
			else
				printf(")");
		}
	}
	return 0;
}
