#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100000+10;
const long long mod=10e9+7;
long long a[maxn],b[maxn];
long long res1[maxn],res2[maxn],flag[maxn];
long long sum[maxn];

void dfs(int now ,int len ,long long *arr,long long *res)
{
	if(flag[now]==1)
	{
		res[len]++;
		return ;
	}
	flag[now]=1;
	dfs(arr[now],len+1,arr,res);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,m,x=1;
	//freopen("put.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		
		memset(res1,0,sizeof(res1));
		memset(res2,0,sizeof(res2));
		memset(flag,0,sizeof(flag));
		
		
		for(int i=0;i<n;i++)
		{
			if(flag[i]==0)
			dfs(i,0,a,res1);
		}
		memset(flag,0,sizeof(flag));
		
		for(int i=0;i<m;i++)
		{
			if(flag[i]==0)
			dfs(i,0,b,res2);
		}
		
//		for(int i=1;i<=n;i++)  cout<<res1[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=m;i++)  cout<<res2[i]<<" ";
//		cout<<endl;
		
		long long r = 1;
		for(int i = 1; i <= n; i++)//��a��ÿ����ͬ���ȵĻ���ʼ���� 
		{
			if(res1[i])//������ڳ���Ϊi�Ļ� 
			{
				int lim=(int)sqrt(i+0.5),temp=0; //��b�г�����Щ��i������ 
				for(int j=1; j<=lim; j++)//��ƽ������ѭ�����������������ж� 
				{
					if(i%j==0)//���b�г���j��i������ 
					{
						temp+=res2[j]*j;//�����Ƕ��پ��ж��ٲ�ͬ��Ӧ��ʽ 
						temp%=mod;
						
						if (j*j!=i)//���i����ƽ��������ôÿ��j���ж�Ӧ������i/j������ƽ���������һ�� 
						{
							int t=i/j;
							temp+=res2[t]*t; 
							temp%=mod;
						} 
					}
				}			
				for(int j=1; j<=res1[i]; j++)
				{
					r*=temp;
					r%=mod;
				}	
			}
		}	
		
		cout<<"Case #"<<x++<<": "<<r<<endl;
	}
	
	return 0;
} 
