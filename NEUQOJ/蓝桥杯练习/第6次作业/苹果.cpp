#include<iostream>
#include<cstring>
using namespace std;
bool able[30];//����Ƿ��ܹ�ʹ�ã����ַ������Ƿ���ֹ�����ĸ 
bool used[30];//��Ǹ���ĸ�Ƿ�ʹ�ù� 
char password[20];//������յĽ�� 
int l;
void solve(int cur,int yuan,int fu,int start)
//�����ֱ�Ϊ��ǰ���ȣ�Ԫ����ĸ������������ĸ��������ʼλ�� 
{
	if(cur==l)//����ǰ���ȷ��� 
	{
		if(yuan<1||fu<2)//��Ԫ�����������㣬����� 
		return;
		password[cur]=' ';
		password[cur+1]='\0';
		cout<<password<<endl;//����ǰ���������� 
		return;
	}
	for(int i=start;i<26;++i)//����ĸ������һ�жϣ���Ϊ���밴��˳������ֻ���ɵ�ǰ������� 
	{
		if(able[i]&&!used[i])//������ĸ����ʹ����û�б�ʹ�ù� 
		{
			char chr=i+'a'-1;//������ʱ�������ڻ�ԭ�ַ� 
			password[cur]=chr;//�����ַ�������������(��ǰ����λ��) 
			used[i]=true;//������ĸ���Ϊ�ù� 
			switch(chr)
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					solve(cur+1,yuan+1,fu,i);//Ԫ������һ�������¸�λ������ 
					break;
				default:
					solve(cur+1,yuan,fu+1,i);//��������һ�������¸�λ������ 
			}
			used[i]=false;//��֧����������ǵý�����������ΪҪ��ʼ�µ�ѭ�� 
		}		
	}
}
int main()
{
	char str[30];
	int sl;
	cin>>l>>sl>>str; 
		memset(able,false,sizeof(able));
		memset(used,false,sizeof(used));
		for(int i=0;i<sl;++i)
			able[str[i]-'a'+1]=true;//�����ֹ�����ĸ���Ϊ�� 
		solve(0,0,0,1);	
	return 0;
}

