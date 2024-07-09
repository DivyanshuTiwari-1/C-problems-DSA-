#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int s, int e ,int x)
{

    if (s > e)
    {
        return -1;
        
    }

    int mid = (s + e) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return binarysearch(arr, n, s, mid - 1, x);
    }
    else
        return binarysearch(arr, n, mid + 1, e, x);
}

int main()
{
    int n, x;
    cin >> n>>x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << " ";
    }
    int s = 0;
    int e = n;
    cout << binarysearch(arr, n, s, e, x);
    return 0;
}