#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    if (n <= 0)
    {
        cout << "no is not present" << endl;
        return -1;
    }

    else if (arr[n - 1] == x)
    {
    
        return n - 1;
    }
    return search(arr, n - 1, x);
}

int main()
{
    int n;
    cout << "enter size of arr" << endl;
    cin >> n;
    int arr[n];

    cout << "enter the arr member" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "no you want to search" << endl;
    cin >> x;
    cout << search(arr, n, x);
    return 0;
}
