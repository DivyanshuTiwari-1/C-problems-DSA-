#include <iostream>
#include<math.h>
using namespace std;

int smalleststepto1(int n)
{
  if (n <= 1)
  {
    return 0;
  }
  int x = smalleststepto1(n - 1);
  int y = INT16_MAX;
  int z = INT16_MAX;
  if (n % 2 == 0)
  {
    y = smalleststepto1(n / 2);
  }

  if (n % 3 == 0)
  {
    z = smalleststepto1(n / 3);
  }
  int ans = min(x, min(y, z)) + 1;
  return ans;
}

int minstepsusingmemoziationhelper(int n, int *ans)
{
  // base case
  if (n <= 1)
  {
    return 0;
  }
  // cheack if the output is already present or not
  if (ans[n] != -1)
  {
    return ans[n];
  }
  // find the out put
  int x = minstepsusingmemoziationhelper(n - 1, ans);
  int y = INT16_MAX;
  int z = INT16_MAX;
  if (n % 2 == 0)
  {
    y = minstepsusingmemoziationhelper(n / 2, ans);
  }
  if (n % 3 == 0)
  {
    z = minstepsusingmemoziationhelper(n / 3, ans);
  }
  int an = min(x, min(y, z)) + 1;
  ans[n] = an;
  return an;
}

int minstepsusingmemoziation(int n)
{
  int *ans = new int[n + 1];
  for (int i = 0; i < n; i++)
  {
    ans[i] = -1;
  }
  return minstepsusingmemoziationhelper(n, ans);
}

int minstepsusingdp(int n)
{

  int *ans = new int[n + 1];
  ans[0] = 0;
  ans[1] = 0;

  for (int i = 2; i <= n; i++)
  {
    int x = ans[i - 1];
    int y = INT16_MAX;
    int z = INT16_MAX;
    if (i % 2 == 0)
    {
      y = ans[i / 2];
    }
    if (i % 3 == 0)
    {
      z = ans[i / 3];
    }
    ans[i] = min(x, min(y, z)) + 1;
  }

  return ans[n];
}

int staircase(int n)
{

  if (n <= 0)
  {
    return 1;
  }
  // 0 significe that one path is compeleted .
  int x = 0, y = 0, z = 0;
  if (n - 1 >= 0)
  {
    x = staircase(n - 1);
  }
  if (n - 2 >= 0)
  {
    y = staircase(n - 2);
  }
  if (n - 3 >= 0)
  {
    z = staircase(n - 3);
  }

  return x + y + z;
}
int stairecaesusingmemzationhelper(int n, int *ans)
{
  // base case
  if (n <= 0)
  {
    return 1;
  }
  // cheack if output is already exists
  if (ans[n] != -1)
  {
    return ans[n];
  }
  // find output and save it
  int x = 0, y = 0, z = 0;
  if (n - 1 >= 0)
  {
    x = stairecaesusingmemzationhelper(n - 1, ans);
  }
  if (n - 2 >= 0)
  {
    y = stairecaesusingmemzationhelper(n - 2, ans);
  }
  if (n - 3 >= 0)
  {
    z = stairecaesusingmemzationhelper(n - 3, ans);
  }
  int output = x + y + z;
  ans[n] = output;
  return output;
}

int stairecaesusingmemzation(int n)
{
  int *ans = new int[n + 1];
  for (int i = 0; i <= n; i++)
  {
    ans[i] = -1;
  }
  return stairecaesusingmemzationhelper(n, ans);
}

int stairecaesusingdp(int n)
{

  int *ans = new int[n + 1];
  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
  }

  return ans[n];
}

int minimumcountofsqrthelper(int n ,int*ans){
   if (n==1){
    return 1;
   }
   for (int i=1;i<=sqrt(n);i++){
       if (i^2==n){
       ans[i]=1;
       }
       int min=minimumcountofsqrthelper(n-i^2,ans);
        ans[i]=min;
     
   }
   int minimum=ans[1];
   for (int i=2;i<=sqrt(n);i++){
        if (ans[i]<=minimum){
          minimum=ans[i];
        }
   }

   return minimum;

}
int minimumcountofsqrt(int n){
    int j=sqrt(n)+1;
   int *ans=new int[j];
   for (int i=0;i<=sqrt(n);i++){
    ans[i]=-1;
   }
   return minimumcountofsqrthelper(n,ans);
}

int minimumnofbts(int h){
   // base case
   if (h<=1){
    return 1;
   }
   int x =minimumnofbts(h-1);
   int y=minimumnofbts(h-2);  // this probleem is similar to fibonacci so time complexity is o(2^n)
   // t(h)=t(h-1)+t(h-2) isko kam karne ke liye ham dp use karsakte matlab jinke liye recursion bar bar ho rha h usko save kar lenge to
   // ye memoization ho  jayega phir whi array me save karke iterative calls karnege to apna o(n) me ho jayega samjh gye n beta
  int mod=pow(10,9)+7;
  int temp=int(long(x*x)%mod);
  int temp1=int(2*long(x*y)%mod);

  int ans =(temp+temp1)%mod;
  return ans;
}


 int minimumnofbtsusingmemozaitionhelper(int h,int *ans){
    if (h<=1){
    return 1;
   }
   if (ans[h]!=-1){
    return ans[h];
   }
   int x =minimumnofbts(h-1);
   int y=minimumnofbts(h-2);
  int mod=pow(10,9)+7;
  int temp=int(long(x*x)%mod);
  int temp1=int(2*long(x*y)%mod);

  int ans1 =(temp+temp1)%mod;
   ans[h]=ans1;
  return ans1;
 }
int minimumnofbtsusingmemozaition(int h){
  int *ans=new int [h+1];
  for (int i=0;i<=h;i++){
       ans[i]=-1;
  }
  return minimumnofbtsusingmemozaitionhelper(h,ans);
}
int minimumnofbtsusingdp(int h){
  int *ans=new int [h+1];
  ans[0]=1;
  ans[1]=1;
  for (int i=2;i<=h;i++){
    int x=ans[i-1];
    int y=ans[i-2];
    int mod=pow(10,9)+7;
  int temp=int(long(x*x)%mod);
  int temp1=int(2*long(x*y)%mod);
  int ans1 =(temp+temp1)%mod;
   ans[i]=ans1;
  }
 return ans[h];


}


int main()
{
  int n;
  cin>>n;
  cout <<minimumcountofsqrt(n);

  return 0;
}