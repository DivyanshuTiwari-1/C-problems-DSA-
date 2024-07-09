#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

pair<int,int>longestconjecative(int a[] ,int n)
{
    pair<int,int>output;
    output.first=0;
    output.second=0;
    unordered_map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        seen[a[i]] = true;
    }
    int maxlength = 1;

    for (int p = 0; p < n; p++)
    {
        int i = 1, j = 1;
        while (seen.count((a[p] + i))> 0)
        {

            i++;
        }

        while (seen.count((a[p] - j)) > 0)
        {

            j++;
        }
        if ((i + j) >= maxlength)
        {
             maxlength = i + j;
            output.first = a[p] - j+1;
            output.second = a[p] + i-1;
        }
    }
    return output;
}
int main()
{ 
    int arr[]={3 ,7 ,2 ,1 ,9, 8, 41};
    pair<int, int>output= longestconjecative(arr,7);

    cout<<output.first<<" "<<output.second;

}