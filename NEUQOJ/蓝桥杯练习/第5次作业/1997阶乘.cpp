#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,a[10000],i,j,len=1,t;
	memset(a,0,sizeof(a));
	a[0]=1;
	n=1977;
	for(i=2;i<=n;i++)//�߾����۳� 
	{
		t=0;//���ڴ����λ���� 
		for(j=0;j<len;j++)
		{
			a[j]=a[j]*i;//������ÿһλ��i��� 
			a[j]+=t;//��������һ�εĽ�λ���� 
			t=a[j]/10;//�ó����ν�λ���� 
			a[j]%=10;//�˼�������ѹλ 
		}
		while(t!=0)//�������ڽ�λ����Ҫ�������鳤�� 
		{
			a[j]=t%10;//�����ʣ��Ľ�λt��λ��ӵ�������漴�� 
			t/=10;
			j++;
		}
		len=j;
	}
	for(i=len-1;i>=0;i--)
	cout<<a[i];
	return 0;
 } 
