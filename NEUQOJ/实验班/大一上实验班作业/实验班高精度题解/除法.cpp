#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int a[505],b[505],c[505];
int compare ()
{
	int i;
	if(a[0]>b[0]) return 1;
	if(a[0]<b[0]) return -1;
	for(i=a[0]; i>0; i--)
	{
		if (a[i]>b[i]) return 1;
		if (a[i]<b[i]) return -1;
	}
	return 1;
}
int main()
{
	int i;
  	//TODO 1: �������� 
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
	//TODO 2�������ַ�����������s1,s2 
	string s1,s2;
	cin>>s1;
	cin>>s2;
	a[0]=s1.length();
	b[0]=s2.length();
	for (i=1; i<=a[0]; i++) a[i]=s1[a[0]-i]-'0';
	for (i=1; i<=b[0]; i++) b[i]=s2[b[00]-i]-'0';
	//TODO 3�� ���� 
	int ans=0;
	while (compare()==1)  //�������ȳ�����ͼ������У�ÿ�����б�������ȥ������ans++ 
	{
		ans++;                             
		for (i=1; i<=a[0]; i++ )
		{
			a[i]-=b[i];
			if (a[i]<0)
			{
				a[i]+=10;
				a[i+1]--;
			}
		}
		while (a[i]==0 && i>=2) i--; //1234-1230=0004 ɾ��ǰ�����Ϊ4 
		a[0]=i;
	}
	cout<<ans<<endl;
}
