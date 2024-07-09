#include <iostream>
using namespace std;

int subs(string input, string output[])
{

    if (input.empty())
    {
        output[0] = " ";
        return 1;
    }
    string input1 = input.substr(1);
    int count = subs(input1, output);
    for (int i = 0; i < count; i++)
    {
        output[i + count] = input[0] + output[i];
    }
    return 2 * count;
}

int main()
{
    string s;
    cin >> s;
    string *output = new string[1000];
    int count = subs(s, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}