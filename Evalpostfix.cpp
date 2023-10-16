#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		
}*top=NULL;


void push(int x)
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

int pop()
{
	int x=-1;
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

int pre(char x)
{
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
		
	return 0;	
		
}

int isOperand(char x)
{
	if(x=='+'||x=='-'||x=='*'||x=='/')
	{
		return 0;
	}
	else 
		return 1;
}

char *IntoPost(char *infix)
{
	int i=0,j=0;
	char *postfix;
	int len =strlen(infix);
	postfix=new char[len+2];
	
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
		{
			postfix[j++]=infix[i++];
		}
		else
		{
			if(pre(infix[i])>pre(top->data))
				push(infix[i++]);
			else
				postfix[j++]=pop();
		}
	}
	while(top!=NULL)
		postfix[j++]=pop();
	
	postfix[j]='\0';
	return postfix;	
	
}	
int Eval(char *postfix)
{
	int i=0;
	int x1,x2,r;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isOperand(postfix[i]))
		{
			push(postfix[i]-'0');
		}
		else
		{
			x2=pop();x1=pop();
			switch(postfix[i])
			{
				case '+':r=x1+x2; break;
				case '-':r=x1-x2; break;
				case '*':r=x1*x2; break;
				case '/':r=x1/x2; break;
			}
			push(r);
		}
	}
	return top->data;
}
int main()
{
//	char *postfix="234*+82/-";
//	cout<<"Result is :"<<Eval(postfix);
	char *infix="a+b*c";
	push('#');
	char *postfix=IntoPost(infix);
	cout<<postfix;
	return 0;
	
	
	
}

