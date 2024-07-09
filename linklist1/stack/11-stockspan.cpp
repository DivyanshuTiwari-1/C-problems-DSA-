
#include <iostream>
using namespace std;
#include <stack>

/*void stockspan(int arr[], int n)
{

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }
    int c = 0, j = n - 1;
    while (!s.empty())
    {
        int x = s.top();
        while (x >= arr[n - 1] && n >= 0)
        {
            c++;
            n--;
        }
        arr[j] = c;
        j--;
        s.pop();
        n = j;
    }
}*/
 void stockspan(int arr[],int p[],int n){
    stack<int>s;
    s.push(0);
    p[0]=1;
  
    for (int i=1;i<n;i++){
      if (arr[i]>=arr[s.top()]){
        s.pop();
        p[i]=(i+1);
        s.push(i);
      }  
    else{
        p[i]=(i-s.top());
    }
}


 }







int main()
{
    int n;
    cin >> n;
    int arr[n];
    int p[n];
    
      for (int i = 0; i < n; i++)
    {
        p[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    stockspan(arr,p, n);
    for (int i = 0; i < n; i++)
    {
        cout << p[i]<<" ";
    }
}