#include<iostream>
#include<cstring>
using namespace std;
int a[20][20],res;
int n,m,x,y;
void dfs(int i,int j)
{
	if(i==n&&j==m)//���������˳���ﵽ�յ㣬�������һ 
	{
		res++;
		return ;
	}
	if(a[i][j]||i>n||j>m) return ;//�����������߽�����Ŀ��Ʒ�Χ ���� �Ѿ��߳��߽���ֱ�ӷ��أ���������һ������ 
	
	dfs(i+1,j);//������һ�� 
	dfs(i,j+1);//������һ�� 
	return ;
}
int main()
{
	
	while(cin>>n>>m>>x>>y)
	{
		memset(a,0,sizeof(a));
		res=0;
		n+=2;m+=2;x+=2;y+=2;//Ϊ�˱�������Խ�磬�����е������½�ƽ��������λ 
		a[x][y]=1;//�������ڵ�λ�ú������Ƶ�����ȫ�����Ϊ1���޷�ͨ�� 
		a[x-2][y+1]=1;
		a[x-2][y-1]=1;  
        a[x-1][y+2]=1;
		a[x-1][y-2]=1;  
        a[x+1][y+2]=1;
		a[x+1][y-2]=1;  
        a[x+2][y+1]=1;
		a[x+2][y-1]=1;  
		dfs(2,2);//��(2,2)����Ϊ��㿪ʼ���� 
		cout<<res<<endl;
	}

	return 0;
}
