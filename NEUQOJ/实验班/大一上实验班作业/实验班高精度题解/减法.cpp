#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int a[505],b[505],c[505];
	int i;
	//TODO 1: ��������
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	//TODO 2�������������֣��ֱ�����ַ���s1��s2�У���ʱû�е���
	string s1,s2;
	cin>>s1;
	cin>>s2;
	//TODO 3���Ƚ�s1��s2��������ʹs1��s2����ôs1Ϊ��������s2Ϊ������������������� - ��
	if (s1.length()<s2.length()  ||(s1.length()==s2.length() && s1<s2) )
	{
		string tmp;
		tmp=s1;
		s1=s2;
		s2=tmp;
		cout<<"-";
	}
	//TODO 4: ����������飬�����ϲ��Ľ�����a���������һ����b���������
	a[0]=s1.length();
	b[0]=s2.length();
	for (i=1; i<=a[0]; i++) a[i]=s1[a[0]-i]-'0';
	for (i=1; i<=b[0]; i++) b[i]=s2[b[00]-i]-'0';
	//����
	c[0]=a[0]; 
	for (i=1; i<=c[0]; i++ )
	{
		c[i]+= (a[i]-b[i]);				//ע����+=��������=,��Ϊc[i]������c[i-1]�Ľ�λ��
		if (c[i]<0)                     		
		{								//    12345     12345	   123 4 5     123 4 5    12 3 45     12 3 45     1 2 345     12345
			c[i]+=10;				    //  -   678 =>    678  =>	 6 7 8 =>    6 7 8 => 	 6 78  =>    6 78  =>     678  =>   678
			c[i+1]--;					//=   00000 	0000-3	   000-1 7	   000-4 7 	  00-1 67	  00-4 67	  0-1 667 	  11667
		}
	}
	while (c[ c[0] ] ==0 && c[0]>=2) c[0]--;      //567-500=067������67 
	for (i=c[0]; i>=1; i--) cout<<c[i];
}
