#include<iostream>
#include<queue>
#include<cstring>
using namespace std;  
struct Node //����ṹ�壬��ŵ�ĺ������ꣻ 
{  
    int x,y;  
};  
  
char mp[555][555];//�������벢��ŵ�ͼ��  
int vis[555][555];//���ڱ�����������  
int dir[4][2]={1,0,-1,0,0,1,0,-1};//���ƶ�������,��Ӧ(x,y)���ƶ�(1,0),(0,1),(-1,0),(0,-1)����������  
int n,m,sx,sy,tx,ty;  
  
bool isok(int x,int y)//�ж�û���߳��߽磻  
{  
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;  
    return false;  
}  
  
bool bfs()//�����������  
{  
    Node st,now;  
    queue<Node>Q;//������У���������Ϊ����õĽṹ�壬���ڴ�ŷ�֧��  
    st.x=sx,st.y=sy;//����㸳��ֵ  
    vis[sx][sy]=1;//�õ�ı���Ϊ�����  
    Q.push(st);//���õ�����β��q.push(x)����X�ӵ����е�ĩ�ˡ�  
    while (!Q.empty())//�����в�Ϊ�գ���������һ����û��������q.empty()������Ϊ�յ�ʱ�򷵻�true��  
    {  
        st=Q.front();//�Ӷ��׿�ʼ������q.frontΪ���ض���Ԫ�أ������类ѹ����е�Ԫ�ء�  
        Q.pop();//������Ҫ����ýڵ㡾q.pop()����������Ԫ�أ����ǲ����᷵�ظ�ֵ��  
        if (vis[tx][ty]>=2)//����ڶ��βȵ��յ㣬����ı���ȫ����������Ե����յ�  
            return true;  
        for (int i=0;i<4;i++)//4��ѭ����������������4�������ƶ�  
        {  
            now.x=st.x+dir[i][0];//����һ����λ���ƶ�����ǰλ�ã�  
            now.y=st.y+dir[i][1];  
            if (isok(now.x,now.y)&&((mp[now.x][now.y]!='X'&&!vis[now.x][now.y])||(now.x==tx&&now.y==ty)))
			//���ȱ�֤��ǰλ��û���߳��߽磬ͬʱ��֤��1.��ǰ���������������û�б��ȹ������� 2.��ǰ��Ϊ�յ㣩
			//����������ֱ��˵����ӵ�ǰλ�õ��䣬���Բ��ñ���������  
            {  
                Q.push(now);//����ǰλ�����  
                vis[now.x][now.y]++;//֤���߹�һ�θõ�  
            }  
        }  
    }  
    return false;  
}  
  
int main()  
{   
    int i,j;  
    while (~scanf("%d%d",&n,&m))  
    {  
        memset(vis,0,sizeof(vis));  
        for (i=1;i<=n;i++)  
        {  
            scanf("%s",mp[i]+1);  
            for (j=1;j<=m;j++)  
                if (mp[i][j]=='X') vis[i][j]++;  
        }  //�����ͼ��������ı����ñ�ǣ� 
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);  //���������յ㣻 
        if (bfs()) printf("YES\n");  
        else printf("NO\n");  
    }  
    return 0;  
}  


