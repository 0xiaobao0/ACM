#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+7;
int a[maxn],b[maxn];//�����±�
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		long long ans=0;
 
		for(int i=1;i<=n;i++)
		{
			//ÿ�μ������x��Ϊ��K��������������ĸ��� sum
			int x=a[i],sum=0,cnt=0,j;
			b[++cnt]=i;//�Ե�ǰԪ��Ϊ��һ��ֵ 
			
			//��¼��i��ʼ��һֱ����k����x��������±� 
			for(j=i+1;j<=n&&cnt<k;j++)
			{
				if(a[j]>x)
				b[++cnt]=j;
			}
 
			
			if(cnt==k)//i֮�����k����x����� 
			{
				int num=1;
				//��k����x�����֮�������ж��ٸ���xС�� 
				for(;j<=n;j++) 
				{
					if(a[j]<x) num++;
					else break;
				}
				sum+=num;
				
				for(j=i-1;j>=1&&cnt>=1;j--)
				{
					if(a[j]<x) sum+=num;//ÿ����һ����XС������������num��������� 
					else//ÿ�γ���һ����x����� 
					{
						if(cnt==1) break;//�Ҳ಻���б�x����� 
						num=b[cnt]-b[cnt-1]; 
						cnt--;//�Ҳ��x���������һ�� 
						sum+=num; 
					}	
				}			
			}
			else//i�Ҳ಻��k����x����� 
			{
				for(j=i-1;j>=1&&cnt<k;j--) 
				{
					if(a[j]>x)
					b[++cnt]=j; //�����ң�ֱ����k����x��� 
				}
				if(cnt==k) 
				{
					sort(b+1,b+cnt+1);
					int num=n-b[cnt]+1;
					sum+=num;
					for(;j>=1&&b[cnt]>=i;j--)
					{
						if(a[j]<x) sum+=num;
						else
						{
							if(b[cnt]==i) break;
							num=abs(b[cnt]-b[cnt-1]);
							cnt--;
							sum+=num;
						}
					}
				}
			}	
			ans+=(long long)sum*x;
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
