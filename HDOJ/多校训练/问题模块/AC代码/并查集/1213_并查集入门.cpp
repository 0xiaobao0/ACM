#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn=1000+10;
int ti,n,m,uf[maxn];

int dfs(int step)
{
	if(uf[step]==step)//�鵽���ڽڵ�ֱ�ӷ��� 
		return step;
	else
		uf[step]=dfs(uf[step]);
	//·��ѹ������������·�ϵ����нڵ�ֱ�Ӻ����ڽڵ��������ӿ��´������ٶ� 
	return uf[step];
}

void ufind(int x,int y)
{
	int fx=dfs(x);//�ҵ�x�����ڽڵ�fx 
	int fy=dfs(y);//�ҵ�y�����ܽ��fy 
	if(fx!=fy)	uf[fy]=fx;//�������һ�����ϣ�Ĭ�Ͻ�fy�����ڽڵ��Ϊfx 
	
	return ;
}

int main()
{
	
	std::ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	
	cin>>ti;
	while(ti--)
	{	
		int x,y,sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) uf[i]=i;
		//��ÿ���ڵ�����ڽڵ���Ϊ�Լ� 
		
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;		
			ufind(x,y);//�������ڵ�����һ�����ϣ���ʼ�ϲ� 
		}
		
		for(int i=1;i<=n;i++)//����ж��м������ڽڵ���м������� 
			if(uf[i]==i)
				sum++;
		cout<<sum<<endl;		
	}

	return 0;
}
