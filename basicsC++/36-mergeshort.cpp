#include <iostream>
using namespace std;
void merge(int a[], int si, int mid, int en)
{
    int i, j, k;
    int n1 = mid - si + 1;
    int n2 = en - mid;
    int b[n1], c[n2];
    for (int i = 0; i < n1; i++)
    {
        b[i] = a[si + i];
    }
    for (int i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }
    i = 0, j = 0, k = si;
    while (i < n1 && j < n2)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = b[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}

void mergeshort(int a[], int si, int en)
{
    if (si >= en)
    {
        return;
    }
    else
    {

        int mid = (si + en) / 2;
        mergeshort(a, si, mid);
        mergeshort(a, mid + 1, en);
        merge(a, si, mid, en);
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
    mergeshort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}