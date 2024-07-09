#include <iostream>
using namespace std;

int subs(int n, string output[])
{
    string input;
    if (n == 0)
    {
        output[0] = " ";
        return 1;
    }

    int num = n % 10;
    n = n / 10;
    int smalloutput = subs(n, output);
    switch (num)
    {
    case 2:
    {
        input = "abc";
        break;
    }
    case 3:
    {
        input = "def";
        break;
    }
    case 4:
    {
        input = "ghi";
        break;
    }
    case 5:
    {
        input = "jkl";
        break;
    }
    case 6:
    {
        input = "mno";
        break;
    }
    case 7:
    {
        input = "pqrs";
        break;
    }
    case 8:
    {
        input = "tuv";
        break;
    }
    case 9:
    {
        input = "wxyz";
        break;
    }
    }
    int anssize = smalloutput * input.size();
    string temp[anssize];
    int k = 0;
    for (int i = 0; i < smalloutput; i++)
    {
        for (int j = 0; j < input.size(); i++)
        {
            temp[k] = output[i] + input[j];
            k++;
        }
    }
    for (int i = 0; i < anssize; i++)
    {
        output[i] = temp[i];
    }
    return smalloutput * input.size();
}

int main()
{
    int n;
    cout << "enter no" << endl;
    cin >> n;

    string *output = new string[1000];
    int count = subs(n, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}