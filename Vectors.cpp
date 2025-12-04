#include <iostream>
#include <cmath>
using namespace std;

struct vec3
{
private:
    float x, y, z;

public:

    vec3(float x=0.0f, float y=0.0f, float z=0.0f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    ~vec3(){}

    vec3(const vec3& orig)
    {
        this->x = orig.x;
        this->y = orig.y;
        this->z = orig.z;
    }

    vec3& operator=(const vec3& orig)
    {
        if(this!=&orig)
        {
            this->x = orig.x;
            this->y = orig.y;
            this->z = orig.z;
        }
        return *this;
    }

    vec3 operator+(const vec3& orig) const
    {
        vec3 c(*this);
        c.x += orig.x;
        c.y += orig.y;
        c.z += orig.z;
        return c;
    }

    vec3 operator-(const vec3& orig) const
    {
        vec3 c(*this);
        c.x -= orig.x;
        c.y -= orig.y;
        c.z -= orig.z;
        return c;
    }

    float operator*(const vec3& orig) const
    {
        return x * orig.x + y * orig.y + z * orig.z;
    }

    bool operator==(const vec3& orig) const
    {
        return (x == orig.x && y == orig.y && z == orig.z);
    }

    float operator~() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    bool operator<=(const vec3& orig) const
    {
        return (~*this<=~orig);
    }

    bool operator>=(const vec3& orig) const
    {
        return (~*this>=~orig);
    }

    bool operator!=(const vec3& orig) const
    {
        return (x != orig.x || y != orig.y || z != orig.z);
    }

    bool operator<(const vec3& orig) const
    {
        return (~*this<~orig);
    }

    bool operator>(const vec3& orig) const
    {
        return (~*this>~orig);
    }

    float operator[](int pos) const
    {
        if(pos<0||pos>2)
        {
            cout<<"Error"<<endl;
            return 42;
        }
        if(pos==0) return this->x;
        if(pos==1) return this->y;
        if(pos==2) return this->z;
    }

    vec3 operator+() const
    {
        float m=~(*this);
        if(m==0)return vec3(0, 0, 0);
        vec3 c(*this);
        c.x/=m;
        c.y/=m;
        c.z/=m;
        return c;
    }

    vec3 operator-() const
    {
        float m=~(*this);
        if(m==0)return vec3(0, 0, 0);
        vec3 c(*this);
        c.x=-c.x/m;
        c.y=-c.y/m;
        c.z=-c.z/m;
        return c;
    }

    vec3& operator++()
    {
        ++this->x;
        ++this->y;
        ++this->z;
        return *this;
    }

    vec3 operator++(int)
    {
        vec3 c(*this);
        ++this->x;
        ++this->y;
        ++this->z;
        return c;
    }

    vec3& operator--()
    {
        --this->x;
        --this->y;
        --this->z;
        return *this;
    }

    vec3 operator--(int)
    {
        vec3 c(*this);
        --this->x;
        --this->y;
        --this->z;
        return c;
    }

    friend ostream& operator<<(ostream& out,const vec3& v);
    friend istream& operator>>(istream& in, vec3& v);

};

ostream& operator<<(ostream& out,const vec3& v)
{
    out<<"x: "<<v.x<<"\ty: "<<v.y<<"\tz: "<<v.z<<endl;
    return out;
}

istream& operator>>(istream& in,vec3& v)
{
    in>>v.x>>v.y>>v.z;
    return in;
}

int main()
{
    vec3 a,b;
    cin>>a>>b;
    cout<<a*b<<endl;
    cout<<a[1]<<endl;

}