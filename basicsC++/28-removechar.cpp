#include <iostream>
using namespace std;

void removechar(string s, char c)
{

    int i = 0, j = 0;
    int l = s.length();

    while (i <l)
    {
         char x=s.at(i);
        if (x == c)
        {  
           
            i++;
        }
       else{
        s.at(j)= x;
        j++;
        i++;
       }
       

    
    }
    j++;
   s.at(j) ='\0';
   

 cout<<s;
}

int main()
{
    string s;
    cout << "enter the world" << endl;
    cin >> s;
    char c;
    cout << "enter the char" << endl;

    cin >> c;
   removechar(s,c) ;
    
      return 0;
}