#include <iostream>
using namespace std;

const int INF=2e9+5;

struct Node
{
    int val;
    Node* next;
    Node* prev;

    Node()
    {
        val=-INF;
        next=nullptr;
        prev=nullptr;
    }
};

struct DLL
{
    Node* head;

    DLL()
    {
        head=new Node;
    }

    ~DLL()
    {
        Node* p=head;
        while(p)
        {
            Node* next=p->next;
            delete p;
            p=next;
        }
    }

};

void add_after(Node* p,int val)
{
    Node* newnode=new Node;
    newnode->val=val;
    newnode->next=p->next;
    newnode->prev=p;
    if(p->next)p->next->prev=newnode;
    p->next=newnode;
}

void add_before(Node* p,int val)
{
    if(p->val==-INF)
    {
        cout<<"Error"<<endl;
        return;
    }
    Node* newnode=new Node;
    newnode->val=val;
    newnode->next=p;
    newnode->prev=p->prev;
    if(p->prev)p->prev->next=newnode;
    p->prev=newnode;
}

void insert(DLL &l,int val)
{
    Node* p=l.head;
    while(p->next)p=p->next;
    add_after(p,val);
}

void print(DLL &l)
{
    Node* p=l.head;
    while(p->next)
    {
        p=p->next;
        cout<<p->val<<" ";
    }
    cout<<endl;
}

void remove_after(Node* p)
{
    if(!p->next)return;
    Node* t=p->next->next;
    delete p->next;
    p->next=t;
    if(t)t->prev=p;
}

void remove(DLL &l,int val,bool remove_all=false)
{
    Node* p=l.head;
    while(p->next)
    {
        if(p->next->val==val)
        {
            remove_after(p);
            if(!remove_all)break;
        }
        else p=p->next;
    }
}

Node* search(DLL &l,int val)
{
    Node* p=l.head->next;
    while(p)
    {
        if(p->val==val)return p;
        p=p->next;
    }
    return nullptr;
}

int main()
{
    DLL l;
    insert(l, 10);
    insert(l, 20);
    insert(l, 30);
    print(l);

    Node* n = search(l, 20);
    if (n) add_after(n, 25);
    print(l);

    remove(l, 20);
    print(l);

    return 0;
}
