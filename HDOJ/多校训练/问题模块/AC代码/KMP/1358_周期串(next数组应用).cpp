#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const ll maxn=1000000+10;

int nex[maxn],n;
string str;

void getnext()
{
	memset(nex,0,sizeof(nex));
	
	int i=0,k=-1;
	nex[0]=-1;
	
	while(i<n)
	{
		if(k==-1||str[i]==str[k])
		{
			k++;
			i++;
			nex[i]=k;
		}
		else
			k=nex[k];
	}
	return ;
}

void kmp()
{
	getnext();
	for(int i=0;i<=n;i++)
	{
		if(nex[i]>0)
		{
			int j=i-nex[i];
			//�����������˵�����ڳ���Ϊj���ִ���Ϊi/j
			//��1�������ַ�������Ϊ2a��ǰ��׺�ص���󳤶�Ϊa
			//	   ��ɿ�������ַ������ص�����ѭ����������
			//��2��������Ϊ3a������ص�����Ϊ2a����a1+a2=a2+a3��a1=a3��
			//     �ɣ�1��֪a1=a2 ������a1=a2=a3,�ô��ɿ���aѭ���������� 
			//��3�������֪��������Ϊ na,����ص�����Ϊ(n-1)a,�ô��ɿ���aѭ��n������
			if(i%j==0) 
				cout<<i<<" "<<i/j<<endl; 
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	
	int ti=1;
	while(cin>>n)
	{
		if(!n) break;
		cin>>str;
		cout<<"Test case #"<<ti++<<endl;
		kmp();
		cout<<endl;
	}
	return 0;
}

