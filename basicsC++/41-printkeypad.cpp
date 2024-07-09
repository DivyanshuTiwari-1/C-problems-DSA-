#include <iostream>
using namespace std;

void printall(int n, string output)
{
    string input;
    int num = n % 10;
    switch (num)
    {
    case 2:
        input = "abc";
        break;
    case 3:
        input = "def";
        break;
    case 4:
        input = "ghi";
        break;
    case 5:
        input = "jkl";
        break;
    case 6:
        input = "mno";
        break;
    case 7:
        input = "pqrs";
        break;

    case 8:
        input = "tuv";
        break;

    case 9:
        input = "wxyz";
        break;
    }
    if (n % 10 == 0)
    {
        cout << output << endl;
        return;
    }
    printall(n / 10, output + input[0]);
    printall(n / 10, output + input[1]);
    printall(n / 10, output + input[2]);
}

int main()
{
    int n;
    cin >> n;
    string input = "";
   

    printall(n, input);
}