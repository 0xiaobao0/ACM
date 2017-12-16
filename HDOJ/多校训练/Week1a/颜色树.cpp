#include<iostream>
#include<cstring>
using namespace std;
const int maxn=20000+100;
int flag[maxn],color[maxn],bi;
int pre[maxn]; //pre[i]�����i�ڵ㷢�������һ���ߵ���� 
int cnt,sum[maxn],size[maxn];
/*
 * sum[i] ��һ��ά�������飬��ʾ��ǰi��ɫ�Ĵ�ʱi��ɫΪ�����ĸ��������Ĵ�С��
 * size[i]����i�Žڵ�������Ľڵ�����;
 */
struct node
{
	int to;//�����߽�βָ��ڵ����� 
	int next;//��һ���ߵ���� 
}edge[maxn*2];

void addedge(int from,int to)//�����ڵ㣬ָ��ڵ� 
{
	edge[bi].to=to;//��bi����ָ��to 
	edge[bi].next=pre[from];//�����ߵ���һ����Ϊ�����ڵ��������һ���ߣ���û����Ϊ-1�� 
	pre[from]=bi;//�������Ѿ������������ڵ㷢���ĵ�һ���߾��Ǳ�bi 
	bi++;//׼��������һ���� 
}

void dfs(int now,int old)
{
	size[now]=1;
	int all=0;
	int last=sum[color[now]];
	for(int i=pre[now];i!=-1;i=edge[i].next)
	{
		int point=edge[i].to; 
		if(point==old) continue;
		dfs(to,now);
		size[now]+=size[to];
		
		
		
		
		
		
		
	}
} 


int main()
{
	while(cin>>n)
	{
		memset(flag,0,sizeof(flag));
		memset(pre,-1,sizeof(re));
		memset(color,0,sizeof(color));
		memset(sum,0,sizeof(sum));
		
		int num=0;
		for(int i=1;i<=n;i++)
		{
			cin>>color[i];//�����i���ڵ���ɫ 
			if(flag[color[i]]==0)//�������ɫû�г��ֹ�����ɫ������һ 
			{
				num++;
				flag[color[i]]=1;
			}	
		}
		bi=0;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			addedge(x,y);
			addedge(y,x);
		} 
		
		dfs(1,1);
		
		
		cout<<"Case "<<++x<<": "<<endl;
	}
	
	
	return 0;
}
