#include<iostream>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
const int maxn=100000+100;
const long long  mod=1000000000+7;
int w[30][maxn];
int val[30],flag[30];
string str[maxn];
int n,MAX;
struct q
{
	int id;
	string value;
}temp[30];

bool cmp(const q &a, const q &b)
{
	for(int i=MAX-1;i>=0;i--)
	{
		if(a.value[i]!=b.value[i]) 
		return  a.value[i]>b.value[i];
	}
}

int main()
{	
	//freopen("input.txt","r",stdin);
	int x=1;
	while(cin>>n)
	{
		memset(w,0,sizeof(w));
		memset(flag,0,sizeof(flag));
		for(int i=0;i<26;i++) temp[i].value="";
		MAX=0;
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
			int len=str[i].size();
			MAX=max(MAX,len);//��¼��󳤶� 
				
			for(int j=0;j<len;j++)
			{
				int pos=len-j-1;
				if(flag[str[i][j]-'a']==0) flag[str[i][j]-'a']=1;//��¼������Щ��ĸ��Ϊ1 
				
				w[str[i][j]-'a'][pos]++;//��¼ÿ����ĸ��ÿλ���ֵĴ��� 
				while(w[str[i][j]-'a'][pos]>=26)//���ִ�����26���λ 
				{
					w[str[i][j]-'a'][pos]-=26;
					w[str[i][j]-'a'][pos+1]++;
					pos++;
					if(pos==MAX) MAX++;//��λ���ж��Ƿ���Ҫ���� 
				}	
			}
			
			if(len>1) flag[str[i][0]-'a']=2;//��¼��Щ��ĸ����Ϊ���Ϊ2 
		}
		
//		for(int i=0;i<26;i++)
//		{
//			if(flag[i]==1)
//			cout<<char(i+'a')<<" ";
//			for(int j=0;j<MAX;j++)
//				cout<<w[i][j]<<" ";
//			cout<<endl;
//		}
		
		
		
		
			//ת���ɽṹ���е��ַ�������SORT���� 
			for(int i=0;i<26;i++)
			{
				for(int j=0;j<MAX;j++)
					temp[i].value+=char(w[i][j]+'a');
				temp[i].id=i;	
			}
			sort(temp,temp+26,cmp);
			
			
//			for(int i=0;i<26;i++)
//			{
//				cout<<char(temp[i].id+'a')<<" ";
//				cout<<temp[i].value<<endl;
//			} 
			
			int ok=0;//�ж��Ƿ�������ĸ�����֣�����������0�ķ������� 
			for(int i=0;i<26;i++)
			{
				if(flag[i]==0)
				{
					ok=1;
					break;
				}
			}
			
				
			//��¼��С�Ŀ���Ϊ0����ĸ 
			int zero=-1;
			for(int i=25;i>=0;i--)
			{
				int t=temp[i].id;
				if(flag[t]!=2)
				{
					zero=t;
					break;
				}
			}
			//cout<<zero<<" "<<char(zero+'a')<<endl;
			
			//��ÿ����ĸ��������ֵ
			//zeroֱ�Ӹ��� 
			if(ok==0)//ȫ���� 
			{
				int i;
				for( i=0;i<26;i++)
				{
					int t=temp[i].id;
					if(t==zero) 
					{
						val[t]=0;
						break;
					} 
					else
						val[t]=25-i;
				}
				i++;	
				for(;i<26;i++)
				{
					int t=temp[i].id;
					val[t]=26-i;
				} 
				
								
			}
			else
			{
				for(int i=0;i<26;i++)
				{
					int t=temp[i].id; 
					val[t]=25-i;
				}
			}
			
			
//			for(int i=0;i<26;i++)
//				if(flag[i]!=0)
//					cout<<char(i+'a')<<" "<<val[i]<<endl;
			
			
			
			//������ֵ������� 
			long long  res=0,xs=1;
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<26;j++)
				{
					if(flag[j]!=0&&w[j][i]!=0)
					{
						res+=val[j]*w[j][i]*xs;
						res%=mod;
					}
				}
				xs*=26;
				xs%=mod;	
			}
			
			
			cout<<"Case #"<<x++<<": ";
			cout<<res<<endl;
			
		
	}
	
	return 0;
}

