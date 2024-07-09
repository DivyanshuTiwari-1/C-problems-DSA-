#include <iostream>
using namespace std;

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

int main()
{
    int n, m;
    cout << "enter rows and column" << endl;
    cin >> n >> m;
    int arr[n][100];
    takeinput(arr, n, m);
    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " " ;
            }
            cout<<endl;
        }
        else
        { int i=n-1;
            while(i>=0)
            {
                cout << arr[i][j] << " " ;
                i--;
            }
            cout<<endl;
        }
    }


    return 0;
}
