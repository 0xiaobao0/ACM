#include <cstdio>
#include <cstring>
#include <iostream>
const int maxn=1000;
int map[maxn][maxn];
char s[maxn];
using namespace std;
int dp(int dl,int dr)
{
	if(dl>=dr)
	{
		return 0;/*�ݹ���ֹ����*/
	}
	if(map[dl][dr]>=0)
	{
		return map[dl][dr];
	}
	if(s[dl]==s[dr])
	{
		map[dl][dr]=dp(dl+1,dr-1);/*������ͬ������Ҫ��*/
		return map[dl][dr];
	}
	else
	{
		map[dl][dr]=dp(dl+1,dr);/*���˲�ͬ����ֱ�ݹ����ң�ȡСֵ*/
		int c=0;
		c=dp(dl,dr-1);
		if(c<map[dl][dr])
		{
			map[dl][dr]=c;
		}
		map[dl][dr]++;
		return map[dl][dr];
	}
}
int main()
{
	gets(s);
	int n=strlen(s);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			map[i][j]=-1;
		}
	}
	dp(0,n-1);
	cout<<map[0][n-1]<<"\n";
	return 0;
}
