#include <iostream>
using namespace std;

pair<int,int>noofzero(int c,int n){
    pair<int,int>p1;
     p1.first=c;
        p1.second=n/10;
        if(n/10==0){
            return p1;
        }
  else  if(n%10==0){
      
       c++;
    }
   
     pair<int,int>p2=noofzero(c,p1.second);
    return p2;
}
int main()
{
  pair<int,int>p3=noofzero(0,10000);
  cout<<p3.first;
}
