#include<iostream>
#include<array>
#include<vector>
using namespace std;
class  Node
{
    public:
        int data;
        Node *next;
        Node *prev;

};
class DoublyLinkedList
{

    Node* first;
    public:
        DoublyLinkedList()
        {
            Node *first=nullptr;
        }
        void create(int A[],int n)
        {
            Node *t,*last;
            int i;
            first=new Node;
            first->data=A[0];
            first->next=first->prev=nullptr;
            last=first;

            for(i=1;i<n;i++)
            {
                t=new Node;
                t->data=A[i];
                t->next=last->next;
                t->prev=last;
                last->next=t;
                last=t;

            }
        }
        void Display()
        {
            Node *p=first;
            while(p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
            
        }
        int Length()
        {
            Node *p=first;
            int l=0;
            while(p)
            {
                l++;
                p=p->next;
            }
            return l;
        }
    //This Inserts after the given index and works for inserting at first posn and any index 
        void Insert(int index,int x)
        {
            Node*p=first;
            Node *t;
            int i;
            if(index<0 || index>Length())
                return;
            if(index==0)
            {
                t=new Node;
                t->data=x;
                t->prev=nullptr;
                t->next=first;
                first->prev=t;
                first=t;
            }
            else
            {
                for(i=0;i<index-1;i++)
                {
                    p=p->next;
                }
                t=new Node;
                t->data=x;
                t->prev=p;
                t->next=p->next;
                if(p->next)
                    p->next->prev=t;
                p->next=t;    
            }    
            

        }
        int Delete(int index)
        {
            Node *p=first;
            int x=-1,i;
             if(index<0 || index>Length())
                return -1;
            if(index==1)
            {
                first=first->next;
                if(first)first->prev=nullptr;
                x=p->data;
                delete(p);


            }
            else
            {
                for(i=0;i<index-1;i++)
                {
                    p=p->next;
                }
                p->prev->next=p->next;
                if(p->next)
                    p->next->prev=p->prev;
                x=p->data;
                delete(p);    
            }
            return x;    
        }
        void Reverse()
        {
            Node *p=first,*temp;
            while (p)
            {
                //Swapping
                temp=p->next;
                p->next=p->prev;
                p->prev=temp;
                p=p->prev;
                if(p!=nullptr && p->next==nullptr)
                    first=p;
            }            
        }
};
int main()
{
    cout<<"Hello World"<<endl;
    int A[]={1,5,7,11,19};
    DoublyLinkedList ob;
    ob.create(A,5);
    //ob.Insert(0,33);
    //cout<<"Deleted ele of the Doubly LL is:"<<ob.Delete(5)<<endl;
    ob.Display();
    ob.Reverse();
    ob.Display();
    cout<<"Length of the Doubly LL is:"<<ob.Length()<<endl;


    


return 0;
}
