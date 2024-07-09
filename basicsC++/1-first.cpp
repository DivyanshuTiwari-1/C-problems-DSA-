#include <iostream>
using namespace std;

void leasearch(int arr[], int n, int key)
{  int i;
  for ( i = 0; i < n; i++)

  {if
     (arr[i] == key)
    {
      cout << "element  found" << endl;
    
      break;
    }
  }
  
    if (i == n)
    {
      cout << "element not found" << endl;
    
      
    }
}

int main()
{
  int arr[5] = {0, 1, 2, 3, 4};
  leasearch(arr, 5, 1);

  return 0;
}
