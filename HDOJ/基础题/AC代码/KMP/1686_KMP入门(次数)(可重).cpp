#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn=1000010;
ll nex[maxn];
string a,b;

void getnext()
{
	int i=0,k=-1;
	int lb=b.size();
	nex[0]=-1;
	
	while(i<lb)
	{
		if(k==-1 || b[i]==b[k])
		{
			i++;
			k++;
			nex[i]=k;
		}
		else
			k=nex[k];
	}
	
	return ;
}

int kmp()
{
	getnext();
	
	int la=a.size();
	int lb=b.size();
	int i=0,j=0,ans=0;
	
	while(i<la)
	{
		
		if(j==-1||a[i]==b[j])
		{
			i++;
			j++;
			
			if(j==lb)	ans++;	//���һ��ƥ����ֱ�Ӽ�һ,nex�����Զ���ǰѰ��ƥ��λ�� 
		}
		else
			j=nex[j];
	}
	return ans;
}

int main()
{
	
	std::ios::sync_with_stdio(false);//��IO 
	//freopen("in.txt","r",stdin);
	int ti;
	cin>>ti;
	while(ti--)
	{
		cin>>b>>a;
		memset(nex,0,sizeof(nex));
		cout<<kmp()<<endl;		
	}
	return 0; 
}
