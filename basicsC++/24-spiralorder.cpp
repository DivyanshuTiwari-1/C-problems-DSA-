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
    cin >> n >> m;

    int arr[n][100];
    takeinput(arr, n, m);

    int count = 0;
    int rs = 0, re = n - 1, cs = 0, ce = m - 1;
    while (rs <= re && cs <= ce)
    {

        for (  cs = 0; cs <= ce; cs++)
        {
            cout << arr[rs][cs];
        } 

        for (rs = rs + 1; rs <= re; rs++)
        {
            cout << arr[rs][ce];
        }

        for (  ce = ce - 1; ce >= cs; ce--)
        {
            cout<< arr[re][ce];
        }
        for ( re = re - 1; re >= rs; re--)
        {
                cout << arr[re][cs];
        }
    }
        return 0;
    
}