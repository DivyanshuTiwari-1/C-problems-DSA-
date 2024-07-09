#include <iostream>
using namespace std;

void binarysearch(int arr[], int n, int x)
{

  int s = 0;
  int e = n;

  while (s < e)
  {
    int mid = (s + e) / 2;
    if (arr[mid] == x)
    {
      cout << "ele found" << endl;

      break;
    }
    else if (arr[mid] > x)
    {
      e = mid - 1;
    }
    else
      (arr[mid] < x);
    {

      s = mid + 1;
    }
  }
  if (s > e)
  {
    cout << "element not found" << endl;
  }
}

int main()
{
  int arr[] = {11, 12, 13, 14, 35};

  binarysearch(arr, 5, 11);

  return 0;
}
