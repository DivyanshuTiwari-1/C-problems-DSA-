#include<iostream>
#include<cstring>
using namespace std ;

/*int main()
{
    string s;
    cin>>s;
    
    int len =s.length();
    cout<<len;
    for (int i=0;i<len;i++)
{
    for (int j=0;j<len-i;j++)
{
    cout<< s.substr(i,j)<<endl;
}

for (int i=0;i<len;i++)
{
    
}*/
void subString(string s, int n)
{
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << endl;
}
 
// Driver program to test above function
int main()
{
    string s = "abcd";
    subString(s,s.length());
    return 0;
}



