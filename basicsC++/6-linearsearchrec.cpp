#include <iostream>
using namespace std;


bool search(int arr[],int n,int x)

{  if (n<=0)
   {
     return false;

   }

else if (arr[n-1]==x)
{
   return true;
}
  else {
    return search( arr,n-1,x);

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
    int x;
    cout<<"no you want to search"<<endl;
    cin>>x;
    cout << search(arr,n,x);
    return 0;
}



