#include<iostream>
#include<string>
using namespace std;
class stack
{
	public:
	int size;	
	int top;
	char *arr;
	
};
int isFull(stack *st)
{
	return st->top==st->size-1;
}
int isEmpty(stack *st)
{
	return st->top==-1;
}
void push(stack *st,char x)
{
	if(isFull(st))
	{
		cout<<"Stack Overflow"<<endl;
	}
	else
		st->top++;
		st->arr[st->top]=x;
	
}
char pop(stack *st)
{
	int n=0;
	if(isEmpty(st))
	{
		cout<<"Stack Underflow"<<endl;
	}
	n=st->arr[st->top];
	st->top--;
	return char(n);
	
}

int peek(stack *st,int i)
{
	int x=-1;
	if(st->top-i+1<0)
	{
		cout<<"Invalid"<<endl;
		return -1;
	}
	else
		x=st->arr[st->top-i+1];
		return x;

		
}

char stacktop(stack *st)
{
	return st->arr[st->top];
}

char stackbottom(stack *st)
{
	return st->arr[0];
}
void display(stack *st)
{
	for(int i=st->top;i>=0;i--)
	{
		cout<<st->arr[i]<<endl;
	}
}
void reverse(stack *st)
{
	//int *temp;
	int n=st->top+1;
	int *temp=new int[n];
	for(int i=0;i<n;i++)
	{
		temp[i]=st->arr[st->top--];
	}
	for(int i=0;i<n;i++)
	{
		push(st,temp[i]);
	}
}
int main()
{
	stack *st=new stack;
	st->size=10;
	st->top=-1;
	st->arr=new char[st->size];
	push(st,'h');
	push(st,'e');
	push(st,'l');
	push(st,'l');
	push(st,'o');
	display(st);
	cout<<"Top element is : "<<stacktop(st)<<endl;
	cout<<"Bottom element is : "<<stackbottom(st)<<endl;
	cout<<"The asked element is : "<<peek(st,10)<<endl;
	reverse(st);
	cout<<"Reversed string is:"<<endl;
	display(st);
	
	
}


