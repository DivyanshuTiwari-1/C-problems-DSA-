#include <iostream>
    using namespace std;

int arraysubset(int arr[], int n, output [] int m=0)
{
if ( n==0){
    m=m+1;
    output[0] =arr[0];
    return ;
}
arraysubset(arr,n-1,output,m);
 int m1 =m*2 +1;
for ( int i=0;i<m1:++){
    output[i+m]=arr[0]+output[i];
}




    
int main()
{
    int n;
    cout << "enter arr size" << endl;
    cin >> n;
    int arr[n];
    string b[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   int count = arraysubset(arr, n, b);
    for (int i = 0; i < count; i++)
    {
        cout << b[i] << endl;
    }
    return 0;
}