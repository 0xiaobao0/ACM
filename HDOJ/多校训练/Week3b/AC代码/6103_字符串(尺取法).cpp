#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int ti;
	cin>>ti;
	while(ti--)
	{
		int n;
		string str;
		cin>>n;
		cin>>str;
		int len=str.size(),ans=0;
		for(int mid=1;mid<len-1;mid++)//������� 
		{
			int r=mid+1 , midr=mid+1;
			int l=mid-1 , midl=mid-1;
			int sum=0;
			while(1)
			{
				while(r<len&&l>=0&&sum<=n)
				{
					sum+=abs(int(str[r]-str[l]));//��midΪ���ļ������Գ��ַ��Ĳ� 
					r++;
					l--;
					
					if(sum<=n) ans=max(ans,r-midr+1);
				}
				if(sum<=n) ans=max(ans,r-midr+1);
				
				if(r>=len||l<0) break;
				
				sum-=abs(int(str[midr]-str[midl]));//��midΪ���ļ�ȥ�ڲ�Գ��ַ��Ĳ� 
				midr++;
				midl--;	
			}
		} 
		
		for(int mid=1;mid<len;mid++) //ż�� 
		{
			int r=mid  , midr=mid; 
			int l=mid-1, midl=mid-1;
			int sum=0;
			while(1)
			{
				while(r<len&&l>=0&&sum<=n)
				{
					sum+=abs(int(str[r]-str[l]));
					r++;
					l--;
					if(sum<=n) ans=max(ans,r-midr+1);
				}
				if(sum<=n) ans=max(ans,r-midr+1);
				
				if(r>=len||l<0) break;
				
				sum-=abs(int(str[midr]-str[midl]));
				midr++;
				midl--;
			}			
		}
		if(ans) cout<<ans-1<<endl;
		else    cout<<0<<endl;
	}
	return 0;
}
