#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,x,y;
	string ans1,ans2;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		cin>>ans1>>ans2;
		int num=0;
		//int wa1=n-x,wa2=n-y;
		for(int i=0;i<n;i++)
		{
			if(ans1[i]==ans2[i])
			num++;
		}
		
		int dif=n-num;//���߲�ͬ����Ŀ 
		int flag=0;
		//��x������٣���X Y��ͬ�Ķ��ǶԵ�
		//��num>=y ,x���ٴ�num-y��
		//��num<y, x���ٴ�y-num;
		if(dif<y) 
		{
			//����ͬ��ȫΪY��X��dif֮���X Y��ͬ����x���ٶ�y-dif 
			if(x>=y-dif&&x<=n-abs(y-num))  flag=1;
		}
		else
		{
			if(x<=n-abs(y-num))				flag=1;
		}
		
		
		if(flag==1)
		cout<<"Not lying"<<endl;
		else
		cout<<"Lying"<<endl;
				
	}
	return 0;
}
