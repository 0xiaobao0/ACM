#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,ssh[20];
int flag[20];//��������Ƿ��ù� 
int su(int x)//�ж��Ƿ�Ϊ�����ĺ��� 
{
	int i;
	if(x<3) return 0;
	
	for(i=2;i<=sqrt(x);i++)
	if(x%i==0) return 0;

	return 1;
}
void dfs(int t)
{
	int i,j;
	if(t==n&&su(ssh[0]+ssh[n-1]))//���ȷ�������β���Ϊ�������� 
	{
		for(i=0;i<n;i++)//��ֱ������������ 
		cout<<ssh[i]<<" ";
		cout<<endl;
		return ;
	}
	else
	{
		for(j=2;j<=n;j++)//��2��ʼ��nѭ���� 
		{
			if(!flag[j]&&su(j+ssh[t-1]))//��������û�б��ù�����������һλ���ֵĺ�Ϊ���� 
			{
				ssh[t]=j;//������������������ĵ�ǰλ�� 
				flag[j]=1;//����ʹ�ù������ñ�� 
				dfs(t+1);//����һ��λ�ü������� 
				flag[j]=0;//����֮��ȡ����ǣ���ʼ�µ�ѭ�� 
			}
		}
	}
}
int main()
{
	int i;
	cin>>n;
	
	if(n%2!=0)//���nΪ��������һ�������γ�������(1��������⿼��) 
	//��Ϊ��������£�������ż����Ȼ���ڣ���β�������������Ϊż������������ 
	{
		if(n==1)
		cout<<1;
		else
		cout<<"No";
		return 0;
	}
	memset(flag,0,sizeof(flag));
	for(i=0;i<n;i++)
	ssh[i]=i+1;//�Ƚ���ʼ���ݰ�˳����������� 
	dfs(1);
	return 0;
 } 
