#include<iostream>
using namespace std;
struct date//����ṹ���������ڴ��������գ�a,b,����ûʲô�õ���б�� 
{
	int year,mounth,day;
	char a,b;
};
bool cmp(struct date a,struct date b)
{
	if(a.year>b.year) return true;//�ȱȽ���� 
	else if(a.year<b.year) return false;
	else 
	{
		if(a.mounth>b.mounth) return true;//Ȼ�����·� 
		else if(a.mounth<b.mounth) return false;
		else
		{
			if(a.day>b.day) return true;//��������� 
			else return false;
		}
	}
}

int main()
{
	int n,j,i=0;
	date ri[1000],temp;
	while(scanf("%d%c%d%c%d",&ri[i].mounth,&ri[i].a,&ri[i].day,&ri[i].b,&ri[i].year)!=EOF) i++;//ÿ�����ڰ������������룬����¼���� 
	n=i;
	for(i=0;i<n;i++)//��ð�� 
	{
		for(j=0;j<n-i-1;j++)
		{
			if(cmp(ri[j],ri[j+1]))//����д�õ�cmp���������������� 
			{
				temp=ri[j];
				ri[j]=ri[j+1];
				ri[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	printf("%02d/%02d/%d\n",ri[i].mounth,ri[i].day,ri[i].year);//�Ҷ�����λ������������0���� 
	
	return 0;
}
