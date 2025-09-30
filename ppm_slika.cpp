#include <iostream>
#include <cmath>
using namespace std;

const int w=256, h=256;

int dist(int x1, int y1, int x2, int y2)
{
    double dx = x1-x2;
    double dy = y1-y2;
    double d=sqrt(2*(dx*dx+dy*dy)); //*2 so the values go from 0 to 256
    return max(static_cast<int>(d),0);
}

struct Pixel
{
    int r,g,b;
};

struct PPM
{
    Pixel a[h][w];
};

void red_radial_gradient(PPM &s)
{
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            /*kvadrat
            s.a[i][j].b=(min(i,h-i)+255-max(j,w-j))/2;
            s.a[i][j].g=s.a[i][j].r=0;
            */

            s.a[i][j].b=0;
            s.a[i][j].g=0;
            s.a[i][j].r=255-dist(i,j,h/2,w/2);
        }
    }
}

void print(PPM &s)
{
    cout<<"P3\n"<<h<<' '<<w<<endl<<255<<endl;
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            cout<<s.a[i][j].r<<" "<<s.a[i][j].g<<" "<<s.a[i][j].b<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    freopen("slika.ppm","w",stdout);
    PPM s;
    red_radial_gradient(s);
    print(s);
}