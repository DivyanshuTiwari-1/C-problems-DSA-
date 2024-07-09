#include <iostream>
#include "priorityqueque1.h"
using namespace std;

int *insertheap(int arr[], int n)
{
    int i = 1;
    while (i < n)
    {
        int cI = i;

        while (cI >= 0)
        {
            int pI = (cI - 1) / 2;
            if (arr[pI] < arr[cI])
            {
                break;
            }
            else
            {
                int temp = arr[pI];
                arr[pI] = arr[cI];
                arr[cI] = temp;
                cI = pI;
            }
        }
        i++;
    }

    return arr;
}
int *removeelement(int arr[], int n)
{
    int j = n - 1;
    while (j > 1)
    {
        int temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
          j--;
        int pI = 0;
        while (pI < j)
        {
            int cI1 = 2 * pI + 1;
            int cI2 = 2 * pI + 2;
            if (cI1 >= j)
            {
                break;
            }
            if (arr[pI] < arr[cI1] && arr[pI] < arr[cI2])
            {
                break;
            }
            else
            {
                if (arr[cI1] < arr[cI2])
                {
                    int temp = arr[cI1];
                    arr[cI1] = arr[pI];
                    arr[pI] = temp;
                    pI = cI1;
                }
                else
                {
                    int temp = arr[cI2];
                    arr[cI2] = arr[pI];
                    arr[pI] = temp;
                    pI = cI2;
                }
            }
        }

        
    }
    return arr;
}
int *heapshort(int arr[], int n)
{
    int *arr1 = insertheap(arr, n);
    int *arr2 = removeelement(arr1, n);
    return arr2;
}

int main()
{
    int arr[] = {2, 6, 8, 5, 4, 3};
    int *arr2 = heapshort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr2[i];
    }
    return 0;
}