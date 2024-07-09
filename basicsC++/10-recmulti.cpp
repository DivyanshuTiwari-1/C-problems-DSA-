#include<iostream>
using namespace std;

int recmulti(int m,int n)
{
   if (n==0)
   {
      return 0;
   }
else 
{
    return ( m+recmulti( m, n-1));
} 

}
int main ()
{
    int m,n;
    cout<<"enter two integers"<<endl;
    cin>>m>>n;
    cout<<recmulti(m,n);
    return 0;
}