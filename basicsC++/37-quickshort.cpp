#include <iostream>
using namespace std;

int partition(int a[], int si, int en)
{
    int i, j, c;
    int x = a[si];
    int count = 0;
    for (int i = si + 1; i <= en; i++)
    {
        if (a[i] < x)
        {
            count++;
        }
    }
    c = si + count;
    int temp = a[c];
    a[c] = a[si];
    a[si] = temp;
    x = a[c];
    i = si, j = en;
    while (i < c && j > c)
    {
        if (a[i] < x)
            i++;
        else if (a[j] > x)
            j--;
        else
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}

void quickshort(int a[], int si, int en)
{

    if (si >= en)
    {
        return;
    }
    else
    {

        int c = partition(a, si, en);
        quickshort(a, si, c - 1);
        quickshort(a, c + 1, en);
    }
}
    int main()
    {
        int n;
        cout << "enterarraysize" << endl;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        quickshort(a, 0, n-1);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        return 0;
    }