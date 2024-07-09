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
    {   int j=0;int count =0;
        int a[n-1];
        for (int i = 0; i <= n - 1; i++)
        {
            if (arr[i] == x)
            {
                a[j]=i; 
                j++;
                count++;
            }
            
        }
         
         for (int i = 0; i <count; i++)
        {
            cout<<a[i]<<" ";
        }
         
        return 0;

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
