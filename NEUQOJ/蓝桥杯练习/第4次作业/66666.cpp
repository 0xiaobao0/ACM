#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	//hei[]��¼�ڵ���ֵ��len[]��¼��ǰ������Ž� 
	int temp,n=0,i,j,hei[25],len[25],lm,max=-1;
	while(scanf("%d",&temp)!=EOF)
	{
		hei[n]=temp;
		n++;
	}
	
	
	memset(len,0,sizeof(len));
	
	//ÿ���¼�һ����������֮ǰ����Ƴ��������Ž� 
	for(i=0;i<n;i++)
	{
		len[i]=1;//��������һö 
		//���µ�����֮ǰ���е������бȽ� 
		for(j=0;j<i;j++)
		{
			//�����֮ǰĳһö������ 
			if(hei[i]<=hei[j])
			{
				//����ö����״̬�µ����Ž�len[j]���ȼ�һ��������ʱ������ 
				lm=len[j]+1;
				//�����״̬��len[i]��,�ͽ���ʱ������ֵ����len[i] 
				if(lm>len[i])
				len[i]=lm;
			}	
		}
		//�ڲ�ѭ��������len[i]Ϊ��ǰλ�����Ž� 
	}
	//ѭ��������len[]Ӧ��������λ�õ����Ž�
	//������Ž��������� 
	for(i=0;i<n;i++)
	{
		if(max<len[i])
		max=len[i];
	}
	
	cout<<max;
	
	return 0;
}
