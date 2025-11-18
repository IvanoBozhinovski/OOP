#include<iostream>
using namespace std;


int gcd(int a,int b)
{
    a=abs(a);
    b=abs(b);
    if (a>b)swap(a,b);
    if (a==0)return b;
    if (a==1)return 1;
    return gcd(a,b%a);
}

// +, -, *, /, ==, <, >
class Frac
{
    int n;
    int d;
public:
    int N () const { return this->n; }
    int D () const { return this->d; }
    void setN(int x) { this->n = x; }
    void setD(int x) { this->d = x; }

    Frac(const int n=0, const int d=1)
    {
        this->n = n;
        this->d = d;
    }

    // Copy C-tor
    Frac (const Frac& orig) {
        this->n = orig.n;
        this->d = orig.d;
    }

    Frac& operator=(const Frac& orig) {
        if (this!=&orig) { // No Self-assignment
            this->n = orig.n;
            this->d = orig.d;
        }
        return *this;
    }

    void print() {
        cout<<this->n <<"/" << this->d;
    }

    Frac operator*(const Frac& b) const {
        Frac c;
        c.n=n*b.n;
        c.d = d*b.d;
        return c;
    }

    Frac operator+(const Frac& b)const
    {
        Frac c;
        c.n=n*b.d+d*b.n;
        c.d=d*b.d;
        return c;
    }

    Frac operator-(const Frac& b) const
    {
        Frac c;
        c.n=n*b.d-d*b.n;
        c.d=d*b.d;
        return c;
    }

    Frac operator/(const Frac& b) const
    {
        Frac c;
        c.n=n*b.d;
        c.d=d*b.n;
        return c;
    }

    bool operator<(const Frac& b) const
    {
        if (d*b.d>0)return n*b.d<d*b.n;
        return n*b.d>d*b.n;
    }

    bool operator>(const Frac& b) const
    {
        if (d*b.d>0)return n*b.d>d*b.n;
        return n*b.d<d*b.n;
    }

    bool operator==(const Frac& b)const
    {
        return n*b.d==d*b.n;
    }

    void reduce()
    {
        int t=gcd(n,d);
        n/=t;
        d/=t;
    }


    ~Frac() {}

};

ostream& operator<<(ostream& o, const Frac& f) {
    o<<f.N() <<"/" << f.D();
    return o;
}

// Frac operator*(const Frac& a, const Frac& b) {
//     Frac c(a);
//     c.setN(a.N() * b.N());
//     c.setD(a.D() * b.D());
//     return c;
// }

int main() {
    Frac a(2,3);
    Frac b(4,6);
    Frac c=a*b,d=a/b,e=a+b,f=a-b;
    cout<<c<<' '<<d<<' '<<e<<' '<<f<<endl;
    cout<<(a<b)<<endl<<(a==b);
    // Global function operator* (Frac, Frac)
    // Member Function operator* (Frac)
    // a * b
    // operator*(a,b)
    // a.operator*(b)

    //.c.print();

}