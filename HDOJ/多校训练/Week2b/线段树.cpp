/*


size(l,r)/(r-l+1) <mid ����ÿ���������Ƿ���� 
����ת����    size(l,r)+mid*l=temp   temp< mid*(r+1)
val[i]����i��Ӧ�����temp��Сֵ 
*/ 

#include<iostream>
using namespace std;
const int maxn=60000+10;
double left,right,mid,tt,val[maxn*4];
int a[maxn],pos[maxn],dif[maxn];//?
void build(int x,int l,int r )
{
	
	val[x]=mid*l;
	dif[x]=0;
	
	if(l==r) return ;
	int m=(l+r)/2;
	build(x*2,l,m);
	build(x*2+1,m+1,r);
}


int main()
{
	int ti,n;
	
	scanf("%d",&ti);
	while(ti--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		left=0.0;right=1.0;
		
		for(int cnt=1;cnt<=20;cnt++) //����0��1֮�䣬����Խ�ྫ��Խ�� 
		{
			int i;
			mid=(left+right)/2; 
			build(1,1,n);//�����߶���
			
			
			
			for(i=1;i<=n;i++) 
			{
				tt=1111111111;
				
				
				
			}
			
		}
	return 0;
} 
