#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 27 /*�ַ���:26Сд��ĸ+'/0'      */
    
    void MakePassWord(char*, int, int, char*, int, int, int*);/*���ڹ�������ĵݹ麯��*/
    void SortCharacterSet(char *); /*��������ַ�����������*/
    
    int main()
    {
    	char CharacterSet[MAX_LENGTH];		/*��������Сд��ĸ��*/
    	char Password[MAX_LENGTH]="/0";		/*������ɵ�password*/
    	int NumOfPassword=0;			/*������ɵ�password����*/
    	int PassLen;				/*���ָ�������볤��*/

   		scanf("%s",CharacterSet);
    
    	SortCharacterSet(CharacterSet); /*Ϊ�������밴��ĸ˳��������Ҫ���ַ�������*/
    	//printf("After sort: %s",CharacterSet);
    
    	printf("/nInput the length of the password:");/*����ָ�������볤��*/
    	scanf("%d",&PassLen);
    
   	MakePassWord(CharacterSet,0,PassLen,Password,0,0,&NumOfPassword);/*���õݹ麯��*/
    	printf("/n");
    	printf("Number of Passwords: %d/n",NumOfPassword);
    }
    
    /*
    	��������ĵݹ麯��
    	����˵����	char* character_set: Сд�ַ���
    		int i: ��ǰȡ���i��Сд�ַ�
    		int pass_len: ָ�������볤��
   		char* password: ��ǰ�Ѿ����ɵĲ�������
   		int NumOfConsonant: ��ǰ���ɵĲ��������У�������ĸ�ĸ���
    		int NumOfVowel: ��ǰ���ɵĲ��������У�Ԫ����ĸ�ĸ���
   		int* NumOfPass: ��ǰ�Ѿ����ɵĺϷ����������
    */
    void MakePassWord(char* character_set, int i, int pass_len,char* password, 
    			  int NumOfConsonant, int NumOfVowel, int * NumOfPass)
    {
    	char TempPass[MAX_LENGTH];
    	strcpy(TempPass,password);  /*Ϊ��ǰ�Ѿ����ɵĲ����������ɸ���*/
    
    	/*�������Сд��ĸ���Ѿ������������н�����ȡ�ᣬ������Ƿ��Ƿ���Ҫ�������*/
    	if(i>=strlen(character_set))
    	{
    		/*�����ǰ���ɵ�������Ԫ���͸��������Լ����볤�ȶ�����Ҫ�����ӡ������*/
    		if((NumOfConsonant>=2 && NumOfVowel>=1) && strlen(TempPass)==pass_len)
    		{
    			printf("%s/n",TempPass);
    		}
    	}
    	else/*������Сд��ĸû�о���ȡ�ᣬ�����ȡ��ĵݹ����*/
    	{
    		
    		/*����ͳ�Ƶ�ǰ���ɵĲ���������Ԫ���͸����ĸ���*/
    		if((((character_set[i]=='a' || character_set[i]=='e') || character_set[i]=='i')
    			|| character_set[i]=='o') || character_set[i]=='u')
    		{
  			NumOfVowel++;
    		}
    		else
    		{
    			NumOfConsonant++;
    		}
    
   			/*����i����ĸ����ȡ�ᣬ��Ϊȡ�����������*/
    		strncat(TempPass,(character_set+i),1); 
    		
    		/*ȡ��ĸiΪ�����һ���֣�����ݹ����*/
    		MakePassWord(character_set,i+1,pass_len,TempPass,
    				NumOfConsonant,NumOfVowel,NumOfPass);
    	
    		/*��ȡiΪ�����һ���֣�����ݹ����*/
    		MakePassWord(character_set,i+1,pass_len,password,
    				NumOfConsonant,NumOfVowel,NumOfPass);
    	}
    }
    
    
    /*��ð�ݷ��Ը����ַ�����������*/
    void SortCharacterSet(char * set)
    {
    	int i;
    	int j;
    	char temp;
    
    	for(i=strlen(set)-1;i>=1;i--)
    	{
    		for(j=0;j<=i-1;j++)
    		{
    			if(set[j]>set[j+1])
    			{
    				temp=set[j];
    				set[j]=set[j+1];
    				set[j+1]=temp;
    			}
    		}
    	}
    }

