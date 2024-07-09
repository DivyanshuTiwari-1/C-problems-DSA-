#include <iostream>
using namespace std;

void removedupli(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] != s[1])
    {
        removedupli(s + 1);
    }
    else
    { int i=1;
        for ( i = 1;s[i]!='\0'; i++)
        {
            s[i-1]=s[i];
        }
            s[i-1]=s[i];
        removedupli(s);
    }
}

int main()
{
    char str[100];
    cout << "enter string " << endl;
    cin >> str;
    
   removedupli(str);
   cout<<str<<endl;
    return 0;
}