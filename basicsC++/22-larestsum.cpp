#include <iostream>
using namespace std;

int largest(int arr[], int n)
{
    int max = arr[0];
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            j = i;
        }
    }
    return j;
}
void takeinput(int arr[][100], int n, int m)
{
    cout << "enter element of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
}

void printinput(int arr[][100], int n, int m)
{
    cout << "your input look like this:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "enter row and column" << endl;
    cin >> n >> m;
    int arr[n][100];
    takeinput(arr, n, m);
    printinput(arr, n, m);

    /*  int arr[n][m];
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
              cin >> arr[i][j];
          }
          cout<<endl;
      }

      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
              cout << arr[i][j];
          }
          cout<<endl;
      } */
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        a[i] = sum;
    }
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];
        }
        b[j] = sum;
    }

    int hi1 = largest(a, n);
    int hi2 = largest(b, m);

    if (a[hi1] >= b[hi2])
    {
        cout << "row"<< " " << hi1 << " " << a[hi1];
    }
    else
        cout << "column"<< " " << hi2 << " " << b[hi2];
    return 0;
}
