#include <iostream>
#include <math.h>
using namespace std;

double geometric(int k)
{
    if (k == 1)
    {
        return 1;
    }
    else
    {
        double h= 1 / pow(2, k - 1) ;
        double ans =( h+ geometric(k - 1));
        return ans;
    }
}
int main()
{
    int k;
    cin>>k;
    cout << geometric(k);
    return 0;
}