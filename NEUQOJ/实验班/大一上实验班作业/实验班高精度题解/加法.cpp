#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int a[505],b[505],c[505];                       //��������a,b�ֱ���������֣�c��������a+b֮��,���� 
	int i;
	//TODO 1: �������㣬����cstring���memset����  
								//memset(������ , 0���� -1 , ����Ҫ��ֵΪ0��-1�ĳ���(һ��Ϊ�������������)) 
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	string s;
	//TODO 2���ַ������벢������������ 
	cin>>s;                                    		//һ����ʱ���ַ��������洢������ַ��� 
	a[0]=s.length();								//a[0]�洢�����ַ���a�ĳ��� 
	for (i=1; i<=a[0]; i++) a[i]=s[a[0]-i]-'0';		//���ոն�����ַ���s����������a�� 
	cin>>s;														
	b[0]=s.length();
	for (i=1; i<=b[0]; i++) b[i]=s[b[00]-i]-'0';
	//TODO 3: �ӷ����� 
	c[0]=max(a[0],b[0]);
	for (i=1; i<=c[0]; i++ )                
	{
		c[i]+=a[i]+b[i];							//ע����+=��������=,��Ϊc[i]������c[i-1]�Ľ�λ�� 
		if (c[i]>=10)                     			//    12345     12345	   12345     12345    12345    12345
		{											//  +   678 =>    678  =>	 678 =>    678 => 	678 =>   678
			c[i]=c[i]-10;							//=   00000 	00013	   00123	 01023	  03023	   13023
			c[i+1]=c[i+1]+1;
		}
	}
	if (c[ c[0]+1 ]!=0) c[0]++;								
	for (i=c[0]; i>=1; i--) cout<<c[i];			   //������� 
	return 0;
}
