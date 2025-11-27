#include <iostream>
using namespace std;

int dummy=42;

class MyVec
{
    private:
    int size;
    int capacity;
    int *elements;

    void _copy(const MyVec& orig);
    public:
    MyVec(int size = 0, int value = 0);
    ~MyVec();
    MyVec(const MyVec& orig);
    MyVec& operator=(const MyVec& orig);
    void print();
    void push(int val);
    void pop();
    void sort();
    int& at(int pos);
    int& front();
    int& back();
    int* data();

    int operator[](int i);
    MyVec operator+(const MyVec& v);
};

int& MyVec::front()
{
    if(this->size==0)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[0];
}

int* MyVec::data()
{
    return this->elements;
}

int& MyVec::back()
{
    if(this->size==0)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[this->size-1];
}

int& MyVec::at(int pos)
{
    if(pos<0 || pos>=this->size)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[pos];
}


MyVec::MyVec(int size, int value)
{
    int capacity = 4;
    while (size >= capacity)
    {
        capacity*=2;
    }
    elements = new int[capacity];
    this->capacity = capacity;
    this->size = size;

    for (int i=0; i<this->size;i++ )
    {
        elements[i] = value;
    }
    //std::cout<<"Constructing finished";
}

MyVec::~MyVec()
{
    delete [] elements;
    //std::cout<<"Destruction Finished";
}

void MyVec::_copy(const MyVec& orig)
{
    this->capacity = orig.capacity;
    this->size = orig.size;
    this->elements = new int[this->capacity];
    for (int i=0; i<this->size; i++)
    {
        this->elements[i] = orig.elements[i];
    }
}

MyVec::MyVec(const MyVec& orig)
{
    _copy(orig);
}
MyVec& MyVec::operator=(const MyVec& orig)
{
    if (this != &orig)
    {
        delete [] this->elements;
        _copy(orig);
    }
    return *this;
}

void MyVec::print() {
    std::cout<<"C: "<< this->capacity << " S: " << this->size <<":\n";
    for (int i=0; i<this->size; i++)
    {
        std::cout<<this->elements[i] << " ";
    }
    std::cout<<std::endl;
}

void MyVec::push(int val)
{
    if (this->size == this->capacity)
    {
        int newcap = this->capacity*2;
        int *tmp = new int[newcap];
        for (int i=0; i<this->size; i++)
        {
            tmp[i] = this->elements[i];
        }
        delete [] elements;
        elements = tmp;
        this->capacity = newcap;
    }

    this->elements[this->size] = val;
    this->size++;
}

void MyVec::pop()
{
    if(this->size==0)return;
    this->size--;

    //reduction of capacity
    if(this->capacity/2>=this->size)
    {
        int newcap=this->capacity/2;
        int *tmp = new int[newcap];
        for (int i=0; i<this->size; i++)
        {
            tmp[i] = this->elements[i];
        }
        delete [] elements;
        elements = tmp;
        this->capacity = newcap;
    }
}

int MyVec::operator[](int i) {
    if (i<0 || i > this->size-1)
    {
        return 42;
    }
    return this->elements[i];
}

MyVec MyVec::operator+(const MyVec& v)
{
    int s=this->size+v.size;
    MyVec ans(s);
    for (int i=0; i<this->size; i++)
    {
        ans.elements[i] = this->elements[i];
    }
    for(int i=0; i<v.size; i++)
    {
        ans.elements[i+this->size] = v.elements[i];
    }
    return ans;
}

void MyVec::sort()
{
    int s=this->size;
    while(s--)
    {
        for(int i=0;i<s;i++)
        {
            if(this->elements[i]>this->elements[i+1])
            {
                swap(this->elements[i], this->elements[i+1]);
            }
        }
    }
}

int main() {
    MyVec t(3, 123),v;
    t.print();

    v.push(999);
    v.push(777);
    v.pop();
    v.push(777);
    v.push(333);
    v.push(122);
    v.push(10112554);

    v.print();
    MyVec r=v+t;
    r.print();
    for(int i=0;i<9;i++)r.push(i);
    r.print();
    r.sort();
    r.at(0)=5;
    r.print();
    cout<<"First: "<<r.front()<<" Last: "<<r.back()<<endl;
    r.print();
    r.pop();
    r.print();
    r.push(1000);
    r.print();
}

