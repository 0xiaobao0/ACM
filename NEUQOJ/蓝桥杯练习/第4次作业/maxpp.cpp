#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1000005
#define INF 0x7fffffff //��������
//a[]������ 
int sum[N],temp[N],a[N];
using namespace std;
int main()
{
	int n,m,i,j,t;
	while(cin>>m>>n)
	{
		
		for(i=1;i<=n;i++) cin>>a[i];
		memset(sum,0,sizeof(sum));
		memset(temp,0,sizeof(temp));
		
		for(i=1;i<=m;i++)//i����ֵĶ��� 
		{
			t=-INF;
			for(j=i;j<=n;j++)//j����ڼ������������ֳܷ�i�� 
			{
				sum[j]=max(sum[j-1]+a[j],temp[j-1]+a[j]);
				temp[j-1]=t;
				t=max(t,sum[j]);
			}
		}
		cout<<t<<endl;
	}
	return 0;
}

//�������˼���Ǵ�n����������m���ӶΣ�����m���Ӷεĺ���󣬵������һ�����������Ӷ����� 
//��������    1 3 1 2 3
//���ǰ�1 2 3 ��3�����ֳ�1�������   ����1+2+3=6

//����  2 6 -1 4 -2 3 -2 3 
//���ǰ� -1 4 -2 3 -2 3 ��6�����ҳ������ӶΣ�������  ��������¾���
// ��һ�� 4
// �ڶ��� 3 -2 3  
// 4+3-2+3=8 


















