#include <iostream>
using namespace std;

template<typename T , typename v>

  /* class Pair
{
    T x;
    T y;

public:
    void setx(T x)
    {
        this->x = x;
    }
    T getx()
    {
        return x;
    }

    void sety(T y)
    {
        this->y = y;
    }
    T gety()
    {
        return y;
    }
};*/
    class Name
{
    T x;
    v y;

public:
    void setx(T x)
    {
        this->x = x;
    }
    T getx()
    {
        return x;
    }

    void sety(v y)
    {
        this->y = y;
    }
    v gety()
    {
        return y;
    }
};

int main(){
   /* Pair<int> p1;
    p1.setx(5);
    p1.sety(10.20);
   cout<< p1.getx()<<" "<<p1.gety()<<endl;*/
  //  Name<int,double> p1;
    Name<Name<int,double>,double> p2;
   Name<int,double>p4;
   p4.setx(10);
   p4.sety(12.35);
    p2.setx(p4);
    p2.sety(10.20);
   // p1.setx(5);
  //  p1.sety(10.20);
  // cout<< p1.getx()<<" "<<p1.gety()<<endl;
  cout<<p2.getx().getx()<<" "<<p2.getx().gety();
  cout<<p2.gety();

}