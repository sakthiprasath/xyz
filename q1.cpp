#include<iostream>
using namespace std;
#include<string.h>
int q=0;

struct node 
{
	char c;
	int count;
	int flag;
	struct node*next;	
};        
struct result
{
	char c;
	int count;
};
void insert(char s[])
{
	int i=0,n=0,flag=0;
	int len=strlen(s);
	struct node *s1[len];
	for(i=0;i<len;i++)
		s1[i]=NULL;
	i=0;
	while(s[i]!='\0')
	{
		if(int(s[i])>=65 &&int(s[i]) <=90)
		{
			n=int(s[i]);
			n=(n-65)%len;
		}
		if(int(s[i])>=97 &&int(s[i]) <=122)
		{
			n=int(s[i]);
			n=(n-97)%len;
		}
		//inside the hash table
		struct node*temp=s1[n];
		struct node *temp2=new node();
				
		if(temp!=NULL)
		{
			int exit_outer_if=0;
			while(temp!=NULL)
			{
				char c=(temp)->c;
				if(temp->count >=1 &&  c==s[i])
				{
					(temp->count)++;
					exit_outer_if=1;
					break;	
				}
				if(temp->next!=NULL)
					temp=temp->next;
				else
					break;
			}	
			if(exit_outer_if==0)
			{
				temp2->c=s[i];
				temp2->count=1;
				flag++;
				temp2->flag=flag;
				temp->next=temp2;
			}
		}
		else
		{
			temp2->c=s[i];
			temp2->count=1;
			flag++;
			temp2->flag=flag;
			temp2->next=NULL;
			s1[n]=temp2;			
		}
		i++;
	}
	
	
}
int main()
{
	int  i=0,n=0;
	char str[]="HelloWorld";
	insert(str);
	return 0;
}
