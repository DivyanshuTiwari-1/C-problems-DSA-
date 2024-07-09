#include <iostream>
#include <math.h>
using namespace std;
 /*int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int permutation(string s, string output[])
{

    if (s.length() == 0)
    {
        output[0] = " ";
        return 1;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string s1 = s.substr(0, i - 1) + s.substr(i + 1, s.length());
        int a = fact(s1.size());
        string output1[100];
        int x = permutation(s1, output1);
        for( int j = 0;j < x; j++)
        {
            output1[j] = s[i] + output1[j];
        }
        for (int k = 0; k < x; k++)
        {
            output[k + i * a] = output1[k];
        }
    }
     int y= fact(s.length());
    return y;
}
*/
void permute(string s, string answer)
{

    if (s.length() == 0)
    {
        cout << answer << " ";
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string s1 = left + right;
        permute(s1, answer + ch);
    }
}
int main()
{
    string s = "ABC";

    string output = " ";
    permute(s, output);
}