#include <iostream>
#include<cmath>
using namespace std;
int loothouse(int n, int *houses)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n==1){
        return houses[0];
    }


    // recursive calls

    int x = loothouse(n - 2, houses + 2) + houses[0];

    int y = loothouse(n - 1, houses + 1);
    return max(x, y);
}
int loothousedp(int n,int *houses){
      int *ans=new int[n];
    ans[0]=houses[0];
    ans[1]=houses[0];
    for (int i=2;i<n;i++){
        int x=ans[i-2]+houses[i];
        int y=ans[i-1];
        ans[i]=max(x,y);
    }
    return ans[n-1];
}
int possibleways(int a,int b, int *ans ,int n){
    if (n==0){
        return 0;
    }
   
   if (ans[0]^b==a){
    return 1;
   }
   int x=possibleways(a-ans[0]^b,b,ans+1,n-1);
   int y=possibleways(a,b,ans+1 ,n-1);

  return x+y;



}

int possibleways(int a,int b){
    int n=sqrt(a);
    int *ans =new int [n+1];
    for (int i=0;i<=n;i++){
        ans[i]=i+1;
    }
    return possibleways(a,b,ans ,n);
}

#include <iostream>
using namespace std;

int coinpossible(int n, int *ans, int sum) {
    // base case
    if (n == 0) {  
        return (sum == 0) ? 1 : 0; // Return 1 if the sum is exactly 0, otherwise return 0
    }

    if (ans[0] > sum) {
        return 0;
    }

    if (ans[0] == sum) {
        return 1; // Only one way to make the change, using all coins of the current denomination
    }

    int x = coinpossible(n, ans, sum - ans[0]); // Include a coin of the current denomination
    int y = coinpossible(n - 1, ans + 1, sum);  // Exclude a coin of the current denomination

    return x + y;
}
int coinpossible_mem1(int n,int *ans ,int sum ,int *output){
    // cheack if ans is already exist
    
     if (output[n]!=-1){
        return output[n];
    }
// base case
    if (n == 0) {  
        return (sum == 0) ? 1 : 0; // Return 1 if the sum is exactly 0, otherwise return 0
    }

    if (ans[0] > sum) {
        return 0;
    }

    if (ans[0] == sum) {
        return 1; // Only one way to make the change, using all coins of the current denomination
    }
   
    int x = coinpossible_mem1(n, ans, sum - ans[0],output); // Include a coin of the current denomination
    int y = coinpossible_mem1(n - 1, ans + 1, sum,output);  // Exclude a coin of the current denomination
     // save the output
       int ou= x + y;
       output[n]=ou;
       return ou;
}





int coinpossible_mem(int n,int *ans ,int sum){
    int *output=new int [n];
    for (int i=0;i<n;i++){
        output[i]=-1;
    }
    return coinpossible_mem1(n,ans,sum,output);
}

string  cointower(int n,int x,int y){
    //dp solutions 
    int *dp=new int [n+1];
    // if i win at n that means b was lose at n-1 and n-x and n-y and vise versa
    dp [n-1]=1;
    if (n-x>=0&&n-y>=0){
    dp [n-x]=1;
    dp[n-y]=1;
    }
    for (int i=2;i<=n;i++){
        if (i-x>=1&&i-y>=1){
             if (dp[i-1]==1 && dp[i-x]==1&& dp[i-y]==1){
                dp[i]=0;
             }
             else {
                dp[i]=1;
             }
        }
        else{
        if (dp[i-1]==1){
            dp[i]=0;

        }
        else{
            dp[i]=1;
        }
        }
    }

    if (dp[n]==1){
        return "beerus";
    }
    else {
        return "whis";
    }
}
int maximumnumberofsubmatrix(int n,int m ,int **matrix){
    // dp solution 
    int **output=new int *[n];
    for (int i=0;i<n;i++){
        output[i]=new int [m];
    }
    // as first row and first colum has only 1 element so if there is zero than square matrix of size is 1 possible else not 
    // so if a[0][i] or a[i][0]==0 that simply means size of sqare matrix with only one element that is 0 hence its sizs is one 
    for (int j=0;j<m;j++){
       if (matrix[0][j]==0){
               output[0][j]==1;
       }
       else output[0][j]==0;
    }
      for (int i=0;i<n;i++){
       if ( matrix[i][0]==0){
               output[i][0]==1;
       }
       else output[i][0]==0;
    }

    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if (matrix[i][j]==0){
            output[i][j]=min(output[i-1][j-1],min(output[i-1][j],output[i][j-1]))+1;
        }
        else 
        output[i][j]=0;
    }
    }
    int max=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (output[i][j]>=max){
                max=output[i][j];
            }
        }
    }
   

 return max;
}
int shortestsubsequance(string s, string t){
    //base case 
    if (s.length()==0|| t.length()==0){
        return 0;
    }
    //if i am not including s[0]
     int ind =t.find(s[0]);
    int x= shortestsubsequance(s.substr(1),t);
    int y=shortestsubsequance(s.substr(1),t.substr(ind+1))+1;
    return max(x,y);
}

int main()
{
    // int houses[] = {10,2,30,20,3,50};
    // cout << loothouse(6, houses);
    // cout<<possibleways(100,2);
    // int ans[]={1,2,3,4,5,6};
    // cout<<coinpossible_mem(6,ans,250);
//         int n,m;
//         cin>>n>>m;
//      int **output=new int* [n];
//      for (int i=0;i<n;i++){
//         output[i]=new int[m] ;
//         for (int j=0;j<m;j++){
//             cin>>output[i][j];
//         }
//      }

//      cout<<maximumnumberofsubmatrix(n,m,output);
//     return 0;
// }
 cout<<shortestsubsequance("babab","babba");
}