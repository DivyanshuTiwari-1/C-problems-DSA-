#include <iostream>
using namespace std;


 bool cheackpali(char name[])
{
    int i = 0;
    int count=0;
    for (int j=0;name[j]!='\0';j++)
    {
        count++;
    }
    int n=count;
    while ((n-1)!= i)
    {
        if (name[i] == name[n-1])
        {
            i++;
            n = n - 1;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    cout << "enter the name you want to search" << endl;
    char name[10];

    cin >> name;
    
    cout <<cheackpali(name);

    return 0;
}