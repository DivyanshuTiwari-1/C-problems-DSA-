#include <iostream>
using namespace std;

void repalcechar(char s[], char c1, char c2)
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] != c1)
    {
        repalcechar(s + 1, c1, c2);
    }
    else
    {
        s[0] = c2;
        repalcechar(s + 1, c1, c2);
    }
}

int main()
{
    char str[100];
    cout << "enter string " << endl;
    cin >> str;
    cout << "enter char& char youwant to repalce" << endl;
    char c1, c2;
    cin >> c1 >> c2;
   repalcechar(str, c1, c2);
   cout<<str<<endl;
    return 0;
}