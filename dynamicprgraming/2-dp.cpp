#include <iostream>
using namespace std;

int minimumcostpathhelper(int **arr, int m, int n, int i, int j)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT16_MAX;
    }

    int x = minimumcostpathhelper(arr, m, n, i, j + 1);

    int y = minimumcostpathhelper(arr, m, n, i + 1, j + 1);
    int z = minimumcostpathhelper(arr, m, n, i + 1, j);

    int cost = min(x, min(y, z)) + arr[i][j];
    return cost;
}

int minimumcostpath(int **arr, int m, int n)
{
    return minimumcostpathhelper(arr, m, n, 0, 0);
}

int mincostpathmemhelper(int **arr, int m, int n, int i, int j, int **output)
{

    // in memoization we just need to do just two step that check if the dolution is presetn than retun and if not save it

    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT16_MAX;
    }
    // cheack if the cost is already present
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    int x = mincostpathmemhelper(arr, m, n, i, j + 1, output);

    int y = mincostpathmemhelper(arr, m, n, i + 1, j + 1, output);
    int z = mincostpathmemhelper(arr, m, n, i + 1, j, output);

    int cost = min(x, min(y, z)) + arr[i][j];
    // save the ans
    output[i][j] = cost;
    return cost;
}
int mincostpathmem(int **arr, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return mincostpathmemhelper(arr, m, n, 0, 0, output);
}
int mincostpathdp(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
    }

    output[m - 1][n - 1] = input[m - 1][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j]; // fill last row
    }
    // fill the last coumn bottom to top
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }
    // fill remaining elements cost
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1])) + input[i][j];
        }
    }
    return output[0][0];
}

int lcs(string s, string t)
{
    // base case
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {

        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}
int lcs_mem(string s, string t, int **ans)
{
    int m = s.size();
    int n = t.size();

    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    // cheack if ans is already exist
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }
    int ans1;
    if (s[0] == t[0])
    {
        ans1 = 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {

        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));

        ans1 = max(a, max(b, c));
    }
    ans[m][n] = ans1;
    return ans1;
}
int lcs_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return lcs_mem(s, t, ans);
}
int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        output[0][i] = 0; // initilize the first row
    }
    for (int j = 1; j <= m; j++)
    {
        output[j][0] = 0; // intilize the first colmn
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i][j - 1];
                int b = output[i - 1][j];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}
int editdistancehelper(string s, string t)
{
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            count++;
        }
    }

    return count;
}

int knapsack01(int n, int *wei,int *v,int w){
    //base case 
    if (w==0|| n==0){
        return 0;
    }
    if (wei[0]>w){
      return  knapsack01(n-1,wei+1,v+1,w);

    }
    int x= knapsack01(n-1,wei+1,v+1,w-wei[0])+v[0];
    int y=knapsack01(n-1,wei+1,v+1,w);
    return max(x,y);


}
int knapsack01helpmem(int *wei,int *v,int n, int w ,int **output){
     if (w==0|| n==0){
        return 0;
    }
    // cheack if output is already exist
    if (output[n][w]!=-1){
        return output[n][w];
    }

    if (wei[0]>w){
        int ans = knapsack01helpmem(wei+1,v+1,n-1,w,output);
        output[n][w]=ans;
        return ans;

    }
    int x= knapsack01helpmem(wei+1,v+1,n-1,w-wei[0],output)+v[0];
    int y=knapsack01helpmem(wei+1,v+1, n-1,w,output);
    int ans = max(x,y);
    output[n][w]=ans;
    return ans ;
}

int knapsack01_mem(int *wei,int *v ,int n ,int w){
    int **output=new int*[n+1];
    for (int i=0;i<=n;i++){
        output[i]= new int [w+1];
        for (int j=0;j<=w;j++){
            output[i][j]=-1;
        }
    }
    return knapsack01helpmem(wei,v,n,w,output);
}
int knapsack01dp(int *wei, int *v, int n, int w) {
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        output[i] = new int[w + 1];
    }

    // Initialize the first row and column with zero
    for (int j = 0; j <= w; j++) {
        output[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        output[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            // Check if the current weight is greater than the current capacity
            if (wei[i - 1] > j) {
                output[i][j] = output[i - 1][j];
            } else {
                int x = output[i - 1][j - wei[i - 1]] + v[i - 1];
                int y = output[i - 1][j];
                output[i][j] = max(x, y);
            }
        }
    }

    int result = output[n][w];

    // Free the dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        delete[] output[i];
    }
    delete[] output;

    return result;
}

  
int main()
{
    //  int m,n;
    //  cin>>m>>n;
    //  int **arr=new int*[m];
    //  for (int i=0;i<m;i++){
    //     arr[i]=new int[n];
    //     for (int j=0;j<n;j++){
    //         cin>>arr[i][j];
    //     }
    //  }
    //  cout<<mincostpathmem(arr,m,n)<<endl;
    //  cout<<mincostpathdp(arr,m,n)<<endl;
  
  int wei[]={1,2,4,5};
  int v[]={5,4,8,6};
  
cout<<knapsack01dp(wei,v,4,5);


}