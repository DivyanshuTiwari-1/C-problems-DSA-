#include <iostream>
#include <math.h>
using namespace std;

int stirngtointe(string s)
{

    if (s.length() == 1)
    {
        return (s[0] - '0');
    }

    double a = stirngtointe(s.substr(1));
    double b = s[0] - '0';
    b = (b * pow(10, s.length() - 1) + a);
    return int(b);
}

int main()
{
    string s;
    cout << "enterstring" << endl;
    cin >> s;
    int l = s.length();
    cout << stirngtointe(s);

    return 0;
}