#include<iostream>
#include<algorithm>
using namespace std;

const double wh=1.0/120,wm=1.0/10,ws=6.0;//���ٶ� 

const double s_h=719.0/120,s_m=59.0/10,m_h=11.0/120;//һ�������١� 

const double sh=120.0/719,sm=10.0/59,mh=120.0/11;//���1����������� 

const double tsh=360.0*120/719,
			 tsm=360.0*10/59,
			 tmh=360.0*120/11;// ���360����������� 
			 
const double time=12*60*60+0.0000001;//������ 

double min(double a,double b)
{
	return a<b?a:b;
}

double max(double a,double b)
{
	return a>b?a:b;
}

int main()
{
	int d;
	while(cin>>d)
	{
		if(d==-1) break;
		double sum=0;
		//��������֮���һ������Ͳ������ʱ�� 
		double beginSH=d*sh, endSH=(360-d)*sh;
		double beginSM=d*sm, endSM=(360-d)*sm;
		double beginMH=d*mh, endMH=(360-d)*mh; 
		
		for(double b1=beginSH,e1=endSH; e1<=time ;b1+=tsh,e1+=tsh) 
		{
			for(double b2=beginSM,e2=endSM; e2<=time ;b2+=tsm,e2+=tsm) 
			{
				if(e2<b1) continue;//SMʱ���δ��SHʱ��Σ��޽���
				if(b2>e1) break;//SMʱ��γ���SHʱ��Σ��޽��� 
				for(double b3=beginMH,e3=endMH; e3<=time ;b3+=tmh,e3+=tmh) 
				{
					if(e3<b1||e3<b2) continue;//MHʱ���δ������ʱ��Σ��޽���
					if(b3>e1||b3>e2) break;//MHʱ��γ�������ʱ��Σ��޽���
					
					double begin=max(b1,max(b2,b3));
					double end=min(e1,min(e2,e3));
					sum+=(end-begin);
				}
			}
		}
		printf("%.3lf\n",(sum/time)*100); 
		
	}
	return 0;
 } 
