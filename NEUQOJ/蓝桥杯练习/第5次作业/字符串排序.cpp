#include<iostream>
#include<string>
using namespace std;
bool cmp(string a,string b)
{
	if(a.length()>b.length()) return true;//������Ȳ�ͬ����ֱ���ж� 
	else if(a.length()<b.length()) return false;
	else
	{
		for(int i=0;i<a.length();i++)//����ӵ�һλ��ʼ������λ�Ƚ� 
		{
			if(a[i]<b[i]) return true;//ע��Ƚϵ�ʱ��ASCII��ԽС����ֵԽ�� 
			else if(a[i]>b[i]) return false;
		}
	}
	return false;
}
int main()
{
	int n,i,j;
	string str[1005],temp;
	cin>>n;
	
	for(i=0;i<n;i++)
	cin>>str[i];
	
	
	for(i=0;i<n-1;i++)//��ð�ݼ��� 
	{
		for(j=0;j<n-i-1;j++)
		{
			if(cmp(str[j],str[j+1]))//д�ñȽϺ������������� ����ǰ�߱Ⱥ��ߴ��ʱ�򽻻� 
			{
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++)//����źõ��ַ��� 
	cout<<str[i]<<endl;
		
	return 0;
 } 
