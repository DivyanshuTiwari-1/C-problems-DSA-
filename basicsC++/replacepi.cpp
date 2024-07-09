#include<iostream>
using namespace std;

 string replacepi (string s,int n ){
    
   if (s.at(0)=="p"&& s.at(1)=="i")
    {
        s.insert(0,"3.14");
        return s;
    }
else
 string  st =s.copy(s,n,2);



 }
 int main(){
string s ("pipipi");

cout<<replacepi(s,6);

return 0;
}