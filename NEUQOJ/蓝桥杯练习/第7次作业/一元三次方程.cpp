#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double x[4];//x[1],x[2],x[3]�ֱ�������� 
double a,b,c,d,u,v;//u��v��Ϊ���ֵı�� 
int i,t;//t�������ý���±� 
double f(double x)
{
     double temp;
     temp=((a*x+b)*x+c)*x+d;//����ǵ����ԭʽ����ȷ�������Լ����ȱȽ� 
     return temp;
}   
int main()
 { 
    	while(cin>>a>>b>>c>>d)
      {
          t=0;
          for(i=-100;i<=100;i++)//ԭ���ķ�Χ��-100~100֮�� 
           {
               u=double(i);//��iǿ��ת����double������Ϊ���� 
               v=u+0.99999;//����ΪС�����5λ��ȷ���ұ�� 
               if(fabs(f(u))<0.00001||f(u)*f(v)<=0)//�����Ƿ��Ͼ��Ȼ����Ҿ���֮���н� 
			   //fabsΪ����������ֵ 
                {
                    t++;//һ���н� 
                    if(fabs(f(u))<0.00001)//���Ƿ��Ͼ��ȣ������Ǽ�Ϊһ���� 
                       x[t]=u;
                    else//����Ļ������ұ���ж��ֲ��� 
                       {
                    	   while((u+0.001<v)&&fabs(f((u+v)/2))>=0.00001)//��֤����С���ұ��ͬʱ�м��ǲ����㾫��  
                           {
                               if(f(u)*f((u+v)/2)<0)//�����������м���֮�� 
                                 v=(u+v)/2;//���м�����Ϊ�ұ�� 
                               else
                                 u=(u+v)/2;//������Ϊ���� 
                           }
                    	   x[t]=(u+v)/2;//���㾫��ֱ����Ϊһ����     
                       }      
                }   
           }   
      cout<<fixed<<setprecision(2)<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
      }
    
     return 0;
 }   
 
