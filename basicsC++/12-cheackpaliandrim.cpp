#include <iostream>
using namespace std;

bool cheackpalindrome(string s, int st,int en)

{

  if (st==en)
  {
    return true ;

  }
 if (s.at(st)!=s.at(en))
    return false ; 

 else 
 return  cheackpalindrome( s, st+1,en-1);

return true;


}


int main()
{
    string s ("aaaaa");
    
    int st=0;
    int en=(s.length()-1);
    
    cout<<cheackpalindrome(s,st,en);
}