#include<iostream>
#include<cstring>
using namespace std;
int m,n,res[30],chu[30];//res���ڴ�������chu���ڴ����ʼ���ݣ� 
void dfs(int dang,int kai)//dang����ǰ�������ĳ��� 
{
	int i;
	if(dang==m)//�����ȷ���Ҫ�� 
	{
		for(i=0;i<m-1;i++)//�򽫸��ַ���������� 
		cout<<res[i]<<" ";
		cout<<res[i]<<endl;
		return;
	}
	for(i=kai;i<n;i++)
	{
		res[dang]=chu[i];//����ʼ����δ����ʹ�õ�ÿһλ�������Է���res����ĵ�ǰλ�� 
		dfs(dang+1,i+1);//����һ��λ�ý���������� 
	}	
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) chu[i]=i+1;//��n������1~n�������鵱�У� 
	dfs(0,0);
	return 0;
 } 
