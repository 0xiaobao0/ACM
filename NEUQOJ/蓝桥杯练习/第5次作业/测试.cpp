#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct room//����ṹ��洢ÿ�����ݣ�����ÿ������ 
{
	double mao,shu;//ÿ������Ķһ���ʽ 
	double xjb;	// �ɸ��ֶһ���ʽ�ó����Լ۱ȣ����õ�λ����è���һ��������� 
};
room food[100500];
bool cmp(const room &a,const room &b)
{
	return a.xjb>b.xjb;//Ϊsort����д��cmp���������Լ۱Ƚ������� 
}
int main()
{
	
	int m,n,i;
	double best;
	while(~scanf("%d %d",&m,&n));
	{
		best=0;
		for(i=0;i<n;i++)
		{
			scanf("%f %f",&food[i].shu,&food[i].mao);//cin>>food[i].shu>>food[i].mao;//����ÿ����������ݲ������Լ۱� 
			food[i].xjb=food[i].shu/food[i].mao;
		}
		sort(food,food+n,cmp);//�Լ۱Ƚ������� 
		
		for(i=0;i<n;i++)
		{
			if(m>=food[i].mao)//���ʣ��è���㹻����ȫ���һ� 
			{
				best+=food[i].shu;//�������� 
				m-=food[i].mao;//è���ۼ� 
			}
			else//������аٷֱȣ���ʣ��è�����Լ۱ȵĻ����һ�Ȼ������ 
			{
				best+=m*food[i].xjb;
				break;
			}
		}
		cout<<fixed<<setprecision(3)<<best<<endl;//�̶���λС��������� 
	}
	return 0;
}

