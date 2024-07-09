#include<iostream>
using namespace std;

int sumofarr(int arr[], int n)
{
    
    if (n <=0)
    {
        return 0;
    }

    else
    {
         
       return ( sumofarr(arr, n - 1)+arr[n-1]);
        
    }
}
int main()
{
    int n;
    cout<<"enter size of arr"<<endl;
    cin >> n;
    int arr[n];
    
cout<<"enter the arr member"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sumofarr(arr, n);
    return 0;
}