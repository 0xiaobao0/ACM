#include<iostream>
using namespace std;
#define num 6
struct que
{ 
	int data[1000];//ģ����У����������� 
	int head;//����ͷ 
	int tail;//����β 
};

struct stack
{
	int data[10];//ģ��ջ������������ 
	int top;//������ 
};


int main()
{
	struct que q1,q2;
	struct stack s;
	int book[10];//��¼������ 
	int i,t;
	
	//���г�ʼ�� 
	q1.head=1;   q1.tail=1;
	q2.head=1;   q2.tail=1;
	//ջ��ʼ�� 
	s.top=0;
	//��������ʼ��
	for(i=1;i<10;i++) book[i]=0; 
	
	//�ֱ�����˷��� 
	for(i=1;i<=num;i++)
	{
		cin>>q1.data[q1.tail];//��� 
		q1.tail++;//��β���Ų 
	}  
	for(i=1;i<=num;i++)
	{
		cin>>q2.data[q2.tail];
		q2.tail++; 
	}
	    
	//��������������ƣ������о���Ϊ��ʱ����ѭ�� 
	while(q1.head<q1.tail&&q2.head<q2.tail) 
	{
		t=q1.data[q1.head];//�׳��� 
		//�ж��Ƿ�Ӯ�� 
		if(book[t]==0)//������û��t 
		{
			//����Ӯ�� 
			q1.head++;//�������Ƴ���
			s.top++; 
			s.data[s.top]=t;//��ջ
			book[t]=1;//��¼t���Ѿ����� 
		}
		else
		{
			//��Ӯ�� 
			q1.head++;
			q1.data[q1.tail]=t;//���ճ����Ʒŵ���β 
			q1.tail++; 
			//��ʣ��������ηŵ���β 
			while(s.data[s.top]!=t)
			{
				book[s.data[s.top]]=0;//ȡ�����ڱ�� 
				q1.data[q1.tail]=s.data[s.top];//�����β 
				q1.tail++;
				s.top--;
			} 
		} 
		/*-------------------------------------------------*/ 
		t=q2.data[q2.head];//�ҳ��� 
		//�ж��Ƿ�Ӯ�� 
		if(book[t]==0)//������û��t 
		{
			//����Ӯ�� 
			q2.head++;//�������Ƴ���
			s.top++; 
			s.data[s.top]=t;//��ջ
			book[t]=1;//��¼t���Ѿ����� 
		}
		else
		{
			//��Ӯ�� 
			q2.head++;
			q2.data[q2.tail]=t;//���ճ����Ʒŵ���β 
			q2.tail++; 
			//��ʣ��������ηŵ���β 
			while(s.data[s.top]!=t)
			{
				book[s.data[s.top]]=0;//ȡ�����ڱ�� 
				q2.data[q2.tail]=s.data[s.top];//�����β 
				q2.tail++;
				s.top--;
			} 
		} 
	}
	
	//�ж���Ӯ 
	if(q2.head==q2.tail) 
	{
		cout<<"��Ӯ����ǰ������Ϊ"; 
		for(i=q1.head;i<q1.tail;i++) cout<<q1.data[i]<<" ";
		cout<<endl;
		if(s.top>0)
		{
			cout<<"������Ϊ";
			for(i=1;i<=s.top;i++) cout<<s.data[i]<<" ";
		}
		else
			cout<<"��������";
	}
	else
	{
		cout<<"��Ӯ����ǰ������Ϊ"; 
		for(i=q2.head;i<q2.tail;i++) cout<<q2.data[i]<<" ";
		cout<<endl;
		if(s.top>0)
		{
			cout<<"������Ϊ";
			for(i=1;i<=s.top;i++) cout<<s.data[i]<<" ";
		}
		else
			cout<<"��������";
	} 
	
	return 0;
} 
