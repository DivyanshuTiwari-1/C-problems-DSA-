#include <iostream>
using namespace std;

void pairstar(string s)
{
    if (s.length() == 1)
    {
        
    }

    if (s[0] == s[1])
    {
      
    }
    pairstar(s.substr(1));
}


int main()
{
    string s;
    cout << "enterstring:" << endl;
    cin >> s;
    cout << pairstar(s);
    return 0;
}