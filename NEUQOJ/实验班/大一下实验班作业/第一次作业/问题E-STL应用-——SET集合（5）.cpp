#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	char a;
	string s;
	set<string> t;
	while(cin>>a>>s)
	{
		if(a=='B')
			t.insert(s);
		else if(a=='A')
		{
			if(t.count(s))
			cout<<"���ý���"<<endl;
			else
			cout<<"û�п��"<<endl;
		}
	}
	return 0;
}
