#include <iostream>
#include <vector>
using namespace std;

const int INF=2e9+5;

struct Node
{
    int val;
    Node* next;

    Node()
    {
        val=-INF;
        next=nullptr;
    }
};

struct LinkedList
{
    Node* head;

    LinkedList()
    {
        head=new Node();
    }

    ~LinkedList()
    {
        Node* q=head,*p=q->next;
        while(p)
        {
            delete q;
            q=p;
            p=p->next;
        }
        delete q;
    }
};

void addnode(Node* p,int val)
{
    Node* newnode = new Node;
    newnode->val = val;
    newnode->next = p->next;
    p->next = newnode;
}

void insert(LinkedList& l,int val)
{
    Node* p=l.head;
    while(p->next)p=p->next;
    addnode(p,val);
}

void remove_next_node(Node* p)
{
    if(!p->next) return;
    Node* q=p->next->next;
    delete p->next;
    p->next=q;
}

void remove_value(LinkedList& l,int val,bool remove_all=false)
{
    Node* p=l.head;
    while(p->next)
    {
        if(p->next->val==val)
        {
            remove_next_node(p);
            if(!remove_all) break;
        }
        else p=p->next;
    }
}

void sorted_insert(LinkedList& l, int val)
{
    Node* p=l.head;
    while(p->next && p->next->val<val)
    {
        p=p->next;
    }
    addnode(p,val);
}

void print(LinkedList& l)
{
    Node* p=l.head;
    if(!p->next)
    {
        cout<<"EMPTY LIST"<<endl;
        return;
    }
    while(p->next)
    {
        p=p->next;
        cout<<p->val<<' ';
    }
    cout<<endl;
}

void bubblesort(LinkedList& l)
{
    bool swapped=true;
    Node* p=l.head->next;
    if(!p) return;

    while(swapped)
    {
        p=l.head->next;
        swapped=false;
        while(p->next)
        {
            if(p->next->val<p->val)
            {
                swap(p->next->val,p->val);
                swapped=true;
            }
            p=p->next;
        }
    }
}

void insertionsort(LinkedList& l)
{
    Node* p=l.head->next;
    if(!p || !p->next) return;
    while(p->next)
    {
        if(p->val<=p->next->val)
        {
            p=p->next;
            continue;
        }
        Node* q;
        for(q=l.head;q->next;q=q->next)
        {
            if(q->next->val>p->next->val) break;
        }
        Node* tmp=q->next;
        Node* t=p->next->next;
        q->next=p->next;
        p->next->next=tmp;
        p->next=t;
    }
}

void sorted_merge(LinkedList& a, LinkedList& b) ///in-place merge, the result is placed in a, no duplicates
{
    insertionsort(a);
    insertionsort(b);
    Node* p=a.head;
    Node* q=b.head;
    int x,y,last=-INF;
    while(p->next && q->next)
    {
        while(p->next && p->next->val==last)
        {
            remove_next_node(p);
        }

        while(q->next && q->next->val==last)
        {
            remove_next_node(q);
        }

        if(!p->next || !q->next) break;
        x=p->next->val;
        y=q->next->val;
        if(x<=y)
        {
            p=p->next;
        }
        else
        {
            Node* t=p->next;
            Node* r=q->next->next;
            p->next=q->next;
            q->next->next=t;
            q->next=r;
            p=p->next;
        }
        last=min(x,y);
    }

    while(q->next)
    {
        while(q->next && q->next->val==last)
        {
            remove_next_node(q);
        }

        if(!q->next)break;
        last=q->next->val;

        Node* t=p->next;
        Node* r=q->next->next;
        p->next=q->next;
        q->next->next=t;
        q->next=r;
        p=p->next;
    }

    while(p->next)
    {
        while(p->next && p->next->val==last)
        {
            remove_next_node(p);
        }

        if(!p->next) break;
        last=p->next->val;
        p=p->next;
    }
    //b.~LinkedList();
}

int main()
{
    LinkedList a,b;
    vector<int> c={6,6,6,6,5,5,5,5,3,3,3,3,3,3}, d={7,7,5,5,5,5,4,4,4,4,4,2,2,2,1,1,1,1};
    for(auto x:c)insert(a,x);
    for(auto x:d)insert(b,x);
    sorted_merge(a,b);
    print(a);
    print(b);
}