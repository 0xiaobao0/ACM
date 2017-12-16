#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const ll maxn=1000000000;
//�Ҳ�һ�������ţ����� 

struct edg
{
	ll x,y,val;
	double k;
}node[50000+50];


bool cmp(const edg &a,const edg &b)
{
	return a.k<b.k;
}

int main()
{
	
	std::ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	
	int ti,n;
	cin>>ti;
	while(ti--)
	{
		cin>>n;
		ll maxx=0;
		for(int i=1;i<=n;i++)
		{
			ll x,y,v;
			double ki;
			cin>>x>>y>>v;
			
			if(x&&y)	ki=(y*1.0)/(x*1.0);
			else if(y==0) ki=0;
			else ki=-maxn-10;
			
			node[i].x=x;
			node[i].y=y;
			node[i].val=v;
			node[i].k=ki;
			
		}
		sort(node+1,node+n+1,cmp);
		
//		for(int i=1;i<=n;i++)
//		cout<<node[i].x<<" "<<node[i].y<<" "<<node[i].k<<endl;

		double k=node[1].k;//���ҳ���Сб�� 
		ll left=0,right=0;
		for(int j=1;j<=n;j++)
		{
			int x=node[j].x,y=node[j].y,v=node[j].val;
			
			if(x==0)//�����Сб��ΪY�� 
			{
				if(y>0) right+=v;//�ϰ����Ϊ�Ҳ� 
				else	left+=v;//�°���Ϊ��� 
			}
			else
			{
				if(k*x-y==0)//ǡ�������б���ϵĵ� 
				{
					if(y>=0)		right+=v;//�ϰ����Ϊ�Ҳ� 
					else if(y<0)	left+=v;//�°���Ϊ���
				}
				else if(k*x-y>0) 	left+=v;//ֱ�����·��ĵ�Ϊ��� 
				else if(k*x-y<0)	right+=v;//���Ϸ��ĵ�Ϊ�Ҳ� 
			}
		}
		//cout<<"*"<<left<<" "<<right<<endl;
		ll sum=left*right;
		
		for(int i=2;i<=n;i++)
		{
			int x=node[i].x,y=node[i].y,v=node[i].val;
			double k=node[i].k;
			
			if(x==0) continue ;
			
			if(k==0)
			{
				if(x<0)	left-=v,right+=v;
				else 	left+=v,right-=v;
			}
			else if(k<0)//б��Ϊ�����ϰ���ĵ�������� 
			{
				if(y>0) left-=v,right+=v;
				else    left+=v,right-=v;
			}
			else//б��Ϊ�����°���ĵ�������� 
			{
				if(y<0) left-=v,right+=v;
				else    left+=v,right-=v;
			}	
			
			if(left*right>sum)
				sum=left*right;
		}
		cout<<sum<<endl;
	}
}
