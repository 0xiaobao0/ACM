#include<iostream>
#include<cstring> 
using namespace std;
long long a[55],b[10010],dp[10010];//dp[i]�����Ϊi�ļ��ϵ����� 
int main()
{
	//freopen("in.txt","r",stdin);
	int ti,n,m;
	scanf("%d",&ti);
	while(ti--)
	{
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp)); 
		
		for(int i=0;i<=m;i++)
		scanf("%d",&b[i]);
		
		int cnt=0;
		dp[0]=1;
		for(int i=1;i<=m;i++)
		{
			int temp=b[i]-dp[i];//����i�ļ�������ȥ 
			for(int j=1;j<=temp;j++)
			{
				a[++cnt]=i;
				for(int k=m;k>=i;k--)
				dp[k]+=dp[k-i];//����i�ģ���Ϊk-i�ļ��������ֱ����һ��i�����Ǻ�Ϊk��i�ļ�������ÿ�ζ�����ͬ��i������
				//��ʱdp[i~m]���ǲ���i�ļ����� 
			} 		
			//��Ϊj�ļ�����(����i) = ��Ϊj�ļ�����(��i) - ��Ϊj-i�ļ�����(����i) 
		}
		for(int i=1;i<cnt;i++) printf("%d ",a[i]);
		printf("%d\n",a[cnt]);
	}
	
	return 0;
}
