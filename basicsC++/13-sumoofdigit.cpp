#include<iostream>
using namespace std;
int sumofdigit(int n){
   
  if (n%10==0)
      {
        return 0;
      }

   else {
     int smalloutput= sumofdigit(n/10);
      
     return ( n%10+smalloutput);
   }

}
int main()
{ int n;
 cout<<"enter the no"<<endl;
 cin>>n;
 int *p=&n;
 cout<<sumofdigit(p);
    return 0;
}