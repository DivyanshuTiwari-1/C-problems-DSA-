#include <iostream>
using namespace std;

int possibleways(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    return  possibleways(n - 1)+possibleways(n - 2)+possibleways(n - 3) ;
}

int main()
{

    int n;
    cout << "Enter no of stair" << endl;
    cin >> n;
    cout <<possibleways(n);
    return 0;
}