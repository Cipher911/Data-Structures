#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
	public:
		char data;
		node *next;
		
}*top=NULL;


void push(char x)
{
	node *t;
	t=new node;
	if(t==NULL)
	{
		cout<<"Stack is full"<<endl;
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
		
	}
	
}

char pop()
{
	char x;
	node *t;
	if(top==NULL)
	{
		cout<<"Stack is Empty"<<endl;
	}
	t=top;
	top=top->next;
	x=t->data;
	delete t;
	return x;
	
	
}

void display()
{
	node *p;
	p=top;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
	cout<<endl;
}
int isbalanced(char *exp)
{
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
				
		}
		else if(exp[i]==')')
		{
			if(top==NULL)
			{
				return 0;
			}
			pop();
		
		}
	}
	if(top==NULL)
	{
		return 1;
	}	
	else
		return 0;	
}
int main()
{
	char *exp="(((a+b*c-d)))";
	//display();
	cout<<isbalanced(exp);
	return 0;
	
	
	
}

