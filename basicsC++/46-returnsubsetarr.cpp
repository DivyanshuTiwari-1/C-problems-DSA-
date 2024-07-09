#include <iostream>
using namespace std;

int sumsubsets(int arr[], int n, int k ,int output[5][5])
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int s1 = sumsubsets(arr, n - 1, k - arr[0], output);
    int output1[s1][0];
    for (int i = 0; i < s1; i++)
    {
        output1[i][0] = arr[0];
    }
    int s2 = sumsubsets(arr, n - 1, k, output);
    

    return s1 + s2;
}

int main()
{
    int n, k;
    cout << "enter arr size " << endl;
    cin >> n;
    cout << "enter arr" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter sum" << endl;
    cin >> k;
    int output[5][5];
    int count = sumsubsets(arr, n, k, output);
    for (int i=0;i<count;i++){
      cout<< output[i][i];
    }
    return 0;
}